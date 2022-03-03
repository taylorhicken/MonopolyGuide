#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Property.h"
#include "Board.h"
#include <vector>
#include <string>
using namespace std;

class Board;

class Player {
    public:
        Player();
        Player(string name);
        void setYou();
        void movePlayer(string tileName);
        bool passedGo(int newLocation);
        void addMoney(int amount);
        
    private:
        string name;
        int balance; // The money the player has
        int currentLocation; // The location on the board
        bool jailed; // If they are in jail or not
        bool you; // If they are the player the guide is trying to help
        int getOutOfJail; // The number of get out of jail cards they own
        vector<Property> properties; // The properties the player owns
        Board *board;
};

#endif