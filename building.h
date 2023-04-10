#ifndef __BUILDING_H__
#define __BUILDING_H__

#include<vector>
#include<string>

class Player;

enum class Monopoly {A1,A2,ENG,HLTH,ENV,S1,S2,MATH};

class Building { // abstract superclass
    private:
        const std::string name;
        int cost; // set price in constructor
    protected:
        Player * owner = nullptr;
        Building(const std::string name, int cost) : name{name}, cost{cost} {} // ctor
        Building(const std::string name) : name{name} {} 
        std::string getName() const;
        void setCost(int cost);
        virtual void setOwner(Player * buyer) = 0; // when unowned building gets bought -> sets price accordingly
    public: // for when player wants to buy -> owner == nullptr
        bool checkOwner(Player * curr) const;
        virtual int getImprovements() const;
        virtual ~Building() {};
        virtual int getCharge() const = 0;
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
        int getImprovements() const override; 
        int getCharge() const override;
        void buyImprovements(int numOfImprovements);
        void sellImprovements(int numOfImprovements);
        ~Academic() override;
};

class Residence : public Building {
    private:
        int rent = 0;
    public:
        void setOwner(Player* buyer) override; // only building class access
        int getCharge() const override;
        Residence(const std::string name); // ctor
};

class Gym : public Building {
    private:
        int multiplier = 0;
    public:
        void setOwner(Player* buyer) override; // only building class access
        int getCharge() const override;
        Gym(const std::string name); // ctor 
};
#endif
