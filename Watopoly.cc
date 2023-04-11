#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <map>
#include "shuffle.h"
#include "player.h"
#include "board.h"
#include "square.h"
#include "building.h"

using namespace std;

int main(int argc, char* argv[]) {
    bool load = false;
    const string True{"true"};
    const string False{"false"};
    int numPlayers;
    vector<Player*> players;
    string cmd;
    int curTurn = 0;
    vector<int> diceVec{1,2,3,4,5,6};
    Shuffle dice1{diceVec};
    Shuffle dice2{diceVec};

    // setup game
    if (argv[1] == True) {
        // load game 
        load = true;
        string s;
        ifstream f{argv[2]};
        getline(f, s);
        numPlayers = stoi(s);
        for (int i = 0; i < numPlayers; ++i) {
            getline(f, s);
            vector<string> line;
            line = Tokenize(s);
            Player *np;
            string name = line[0];   
            if (line.size() == 6) {
                np = new Player{name, stoi(line[3]), stoi(line[4]), stoi(line[2]), line[1][0], stoi(line[5])};
            }
            else {
                np = new Player{name, stoi(line[3]), stoi(line[4]), stoi(line[2]), line[1][0], 0};
            }
            players.emplace_back(np); 
        }
    } else {
        // new game 
        vector<char> pieces{'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
        char chosenPiece;
        string playerName;
        cout << "Welcome to Watopoly! How many players? (max of 8 players)" << endl;
        cin >> numPlayers;
        if (numPlayers > 8 || numPlayers <= 0) { // checks for range, exits if invalid.
            cout << "Invalid Number of Players. Exiting program..." << endl;
            exit(0);
        }
        for (int i = 0; i < numPlayers; ++i) {
            cout << " " << endl;
            cout << "Player " << i + 1 << " what is your name?: "<< endl;
            try {
                cin >> playerName;
                if (cin.eof()) {
                    throw runtime_error("EOF reached");
                }
            } catch (const exception& e) {
                cout << "Invalid Behaviour. Exiting program..." << endl;
                exit(0);
            }
            cout << " " << endl;
            cout << "Hi " << playerName << "! Here are the available 'Pieces' you can pick from:"<< endl;
            for (auto p: pieces) {cout << "[" << p << "] ";}
            cout << endl;
            cout << " " << endl;
            cout << "Please pick a piece: " << endl;
            bool cont = false;
            try {
                while(true) { // checks for valid piece
                    cin >> chosenPiece;
                    if (cin.eof()) {
                        throw runtime_error("EOF reached");
                        break;
                    }
                    for (auto j = pieces.begin(); j != pieces.end(); ++j) {
                        if (*j == chosenPiece) {
                            pieces.erase(j);
                            cont = true;
                            break;
                        }
                    }

                    if (cont) {
                        cout << playerName << " have chosen " << "[" << chosenPiece << "]" << endl;
                        break;
                    } else {
                        cout << " " << endl;
                        cout << "Invalid Selection. " << "Please try again." << endl;
                    }
                }
            } catch (const exception& e) {
                cout << "Invalid Behaviour. Exiting program..." << endl;
                exit(0);
            }
            Player *np = new Player{playerName, chosenPiece};
            players.emplace_back(np);
        }
    }

    if (argv[3] == True) {
        // turn on testing mode
        cout << "testing" << endl;
    }

    theBoard board{players};
     
    if (load) {
        board.init(argv[2], numPlayers);
    } else {
        board.init();
    }

    while (numPlayers > 1) {
        map<string, bool> cmds = {
            {"roll",true},
            {"next",false},
            {"trade",true},
            {"improve",true},
            {"mortgage",true},
            {"unmortgage",true},
            {"bankrupt",false},
            {"assets",true},
            {"all",true},
            {"save",true},
            {"payTims",false}, // only for dc tims line
            {"useTims",false} // only for dc tims line
        };

        map<string, bool> bankruptcmds = {
            {"roll",false},
            {"next",false},
            {"trade",true},
            {"improve",true},
            {"mortgage",true},
            {"unmortgage",true},
            {"bankrupt",true},
            {"assets",true},
            {"all",true},
            {"save",true},
            {"payTims",false}, // only for dc tims line
            {"useTims",false} // only for dc tims line
        };
        string cmd;
        Player* cur = players[curTurn];
        // check DC Tims Line (update commands)

        if (cur->square == 10 && cur->place != 0) { // at dc tims line 
            cmds["payTims"] = true;
            // add useTims?
            if (cur->timsCups > 0) {
                cmds["useTims"] = true;
            }
        }

        cout << cur->name << " it's your turn!" << endl;

        while (true) { // loop for current player
            Building* landed;
            map<string, bool> ccc;
            if (cur->money < 0) {
                ccc = bankruptcmds;
            } else {
                ccc = cmds;
            }

            cout << "Available Commands: " << endl;
            for (auto it = ccc.begin(); it != ccc.end(); ++it) {
                if (it->second == true) {
                    cout << "<" << it->first << "> ";
                }
            }
            
            try {
                while (true) {
                    cin >> cmd;
                    bool valid = false;
                    if (cin.eof()) {
                        throw runtime_error("EOF reached");
                        break;
                    }

                    for (auto it = ccc.begin(); it != ccc.end(); ++it) {
                        if (it->second == true && cmd == it->first) {
                            valid = true;
                            break;
                        }
                    }
                    if (valid) {break;}
                    cout << "Invalid Command. Please Try Again" << endl;
                }
            } catch (const exception& e) {
                cout << "Invalid Behaviour. Exiting program..." << endl;
                exit(0);
            }
            
            // cmd is now a valid and available command
            if (cmd == "roll") {
                if (cur->square == 10 && cur->place != 0) { // player is at tims line
                    if (dice1.roll() == dice2.roll()) { // if roll double, exit. 
                        cout << "Double! roll again to move." << endl;
                        cur->place = 0;
                    } else { // don't move? 
                        cout << "Not a double, try again next turn." << endl;
                        cmds["roll"] = false;
                        cmds["next"] = true;
                        cur->place--;
                    }

                    if (cur->place == 0 && cmds["roll"] == false) { // on last roll
                        cmds["next"] = false;
                    }
                } else {
                    cur->place = 0;
                    int steps = dice1.roll() + dice2.roll();
                    landed = board.move(players[curTurn], steps);
                    cmds["roll"] = false;
                    cmds["next"] = true;
                    SpecialType st = landed->checkType();
                    if (cur->square - steps < 0) {
                        board.collectOsap(cur);
                    }
                    if (st == SpecialType::GoToTims) {
                        board.goTims(cur);
                    } else if (st == SpecialType::SLC) {
                        board.SLC(cur);
                    } else if (st == SpecialType::NH) {
                        board.NH(cur);
                    } else if (st == SpecialType::Goose) {
                        board.gooseNest(cur);
                    } else if (st == SpecialType::Tuition) {
                        board.tuition(cur);
                    } else if (st == SpecialType::Coop) {
                        board.coopFee(cur);
                    } else if (st == SpecialType::Residence || st == SpecialType::Gym || st == SpecialType::Academic) {
                        int rent = landed->getBuilding()->getCharge();
                        if (landed->getBuilding()->checkOwner(cur)) {
                            continue;
                        } else if (landed->getBuilding()->getOwner() == "BANK") {
                            cout << "Would you like to buy this property? " << landed->getBuilding()->getName() << " {y / n}" << endl;
                            string resp;
                            cin >> resp;
                            if (resp == "y") {
                                cur->money -= landed->getBuilding()->getCost();
                                landed->getBuilding()->setOwner(cur);
                            } else {
                                board.auction(landed->getBuilding());
                            }
                        } else {
                            cur->money -= rent;
                            for (auto p : players) {
                                if (landed->getBuilding()->checkOwner(p)) {
                                    p->money += rent;
                                }
                            }
                        }
                    }
                }
                cout << board;
            } else if (cmd == "next") {
                break;
            } else if (cmd == "save") {
                string file;
                cin >> file;
                board.save(file);
            } else if (cmd == "assets") {
                board.assets(cur);
            } else if (cmd == "all") {
                board.all();
            } else if (cmd == "improve") {
                cout << "Building to Improve:" << endl;
                string building;
                try {
                    cin >> building;
                    if (cin.eof()) {
                        throw runtime_error("EOF reached");
                    }

                } catch (const exception& e) {
                    cout << "Invalid Behaviour. Exiting program..." << endl;
                    exit(0);
                }
                cout << "Buy or Sell Improvements (enter 'buy' or 'sell')" << endl;
                string option;
                try {
                    while (true) {
                        cin >> option;
                        if (cin.eof()) {
                            throw runtime_error("EOF reached");
                            break;
                        }

                        if (option != "buy" && option != "sell") {
                            cout << "Please Enter Either 'buy' or 'sell'" << endl;
                        } else {
                            break;
                        }
                    }
                    
                    
                } catch (const exception& e) {
                    cout << "Invalid Behaviour. Exiting program..." << endl;
                    exit(0);
                }

                // now valid input. 

                if (option == "buy") {
                    board.buyImprovements(cur, building);
                } else if (option == "sell") {
                    board.sellImprovements(cur, building);
                }

            } else if (cmd == "mortgage") {
                cout << "Building to Mortgage:" << endl;
                string building;
                try {
                    cin >> building;
                    if (cin.eof()) {
                        throw runtime_error("EOF reached");
                    }

                } catch (const exception& e) {
                    cout << "Invalid Behaviour. Exiting program..." << endl;
                    exit(0);
                }

                board.mortgage(players[curTurn], building);


            } else if (cmd == "unmortgage") {
                cout << "Building to Unmortgage:" << endl;
                string building;
                try {
                    cin >> building;
                    if (cin.eof()) {
                        throw runtime_error("EOF reached");
                    }

                } catch (const exception& e) {
                    cout << "Invalid Behaviour. Exiting program..." << endl;
                    exit(0);
                }

                board.unmortgage(players[curTurn], building);
            } else if (cmd == "trade") {
                cout << "Player To Trade With:" << endl;
                Player * toTrade = nullptr;
                string player;
                bool isPlayer = false;
                try {
                    cin >> player;
                    if (cin.eof()) {
                        throw runtime_error("EOF reached");
                    }
                    for (auto i : players) {
                        if (i->name == player) {
                            isPlayer = true;
                            toTrade = i;
                        }
                    }              
                } catch (const exception& e) {
                    cout << "Invalid Behaviour. Exiting program..." << endl;
                    exit(0);
                }
                if (!isPlayer) {
                    cout << "Not a Valid Player. Please Try Again" << endl;
                    continue;
                }

                // now we have player, prompt of strings

                cout << "What Are You Offering?" << endl;
                string give;
                try {
                    cin >> give;
                    if (cin.eof()) {
                        throw runtime_error("EOF reached");
                    }
                } catch (const exception& e) {
                    cout << "Invalid Behaviour. Exiting program..." << endl;
                    exit(0);
                }

                cout << "What Are You Receiving?" << endl;
                string receive;
                try {
                    cin >> receive;
                    if (cin.eof()) {
                        throw runtime_error("EOF reached");
                    }
                } catch (const exception& e) {
                    cout << "Invalid Behaviour. Exiting program..." << endl;
                    exit(0);
                }

<<<<<<< Updated upstream
                board.trade(players[curTurn],toTrade, give, receive);
            } else if (cmd == "payTims") {
                
            } else if (cmd == "useTims") {
                
=======
                board.trade(cur, toTrade, give, receive);
>>>>>>> Stashed changes
            }
        }

        cout << board;
        curTurn++;
        if (curTurn == numPlayers) curTurn = 0;
   }
}
