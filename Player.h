#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
    public:
        Player();
        
    private:
        int balance;
        int numCards = 10;
        int currentLocation;
        bool jailed;
        Card cards[10];
};

#endif