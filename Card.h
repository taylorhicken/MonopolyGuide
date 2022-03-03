#ifndef CARD_H
#define CARD_H

#include "Player.h"

class Card {
    public:
        Card();
        enum CardType {
            ADVANCE,
            ADVANCE_UTILITY,
            ADVANCE_RAILROAD,
            BANK_PAY,
            GET_OUT_OF_JAIL,
            GO_BACK_THREE,
            GO_TO_JAIL,
            REPAIRS,
            FINE,
            PAY_EACH_PLAYER
        };
    private:
};

class Advance : public Card {
    public:
        Advance(string location);
        bool checkPassGo();
    private:
        string location;
};

class AdvanceUtility : public Card {
    public:
        AdvanceUtility();
        int findNextUtility(int currentLocation);
        Player findUtilityOwner();
        int calculateCost(int diceRoll);
        bool checkPassGo();
    private:
        int ownOneMultiplier;
        int ownTwoMultiplier;
};

class AdvanceRailroad : public Card {
    public:
        AdvanceRailroad();
        int findNextRailroad(int currentLocation);
        Player findRailroadOwner();
        int calculateCost();
        bool checkPassGo();
    private:
        int cost[4];
};

class BankPay : public Card {
    
}


#endif