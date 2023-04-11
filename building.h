#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <vector>
#include <string>
#include "player.h"

enum class Monopoly {A1,A2,ENG,HLTH,ENV,S1,S2,MATH};

class WTH {
        std::string m_message;
    public:
        WTH(const std::string & message) : m_message(message) {} 
        std::string message() const {
            return m_message;
        }
};

class Building { // abstract superclass
    private:
        const std::string name;
        int cost; // set price in constructor
    protected:
        Player* owner = nullptr;
        Building(const std::string name, int cost) : name{name}, cost{cost} {} // ctor
        Building(const std::string name) : name{name} {} 
        void setCost(int cost);
    public:
        bool mortgaged = false;
        std::string getName() const;
        virtual void setOwner(Player * buyer) = 0; // when unowned building gets bought -> sets price accordingly
        virtual void removeOwner() = 0; // when unowned building gets bought -> sets price accordingly
        bool checkOwner(Player * curr) const;
        int getCost();
        int nameToMono(std::string name);
        virtual int getImprovements() const;
        std::string getOwner() const;
        virtual ~Building() {};
        virtual int getCharge() const = 0;
        virtual void buyImprovements(int numOfImprovements);
        virtual void sellImprovements(int numOfImprovements);
        virtual bool checkMonopoly() const;
        virtual int getImprovementCosts() { return 0; }
};

class Academic : public Building {
    private:
        Monopoly m;
        int improveCost; // improve cost
        int tuition;
        int improvements;
    public:
        Academic(const std::string name, int improvements = 0); // ctor for construction
        void setOwner(Player* buyer) override;
        void removeOwner() override;
        int getImprovements() const override; 
        int getCharge() const override;
        bool checkMonopoly() const override;
        void buyImprovements(int numOfImprovements) override;
        void sellImprovements(int numOfImprovements) override;
        int getImprovementCosts() override;
        ~Academic() override;
};

class Residence : public Building {
    private:
        int rent = 0;
    public:
        void setOwner(Player* buyer) override; // only building class access
        void removeOwner() override;
        int getCharge() const override;
        Residence(const std::string name); // ctor
};

class Gym : public Building {
    private:
        int multiplier = 0;
    public:
        void setOwner(Player* buyer) override; // only building class access
        void removeOwner() override;
        int getCharge() const override;
        Gym(const std::string name); // ctor 
};
#endif
