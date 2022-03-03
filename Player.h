#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include <string>
using namespace std;

class Player {
    public:
        Player();
        Player(string name);
        void setNextPlayer();
        void setYou();
        
    private:
        string name;
        int balance; // The money the player has
        int currentLocation; // The location on the board
        bool jailed; // If they are in jail or not
        bool you; // If they are the player the guide is trying to help
        vector<Card> cards; // The cards in their inventory
};

#endif