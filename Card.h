#ifndef CARD_H
#define CARD_H

#include "Player.h"

class Card {
    public:
        Card();
        bool checkPassGo(); // Check if the player will pass go
        void payBank(Player &player); // Remove money from players account
        void setMessage(string message) { this->message = message; }
        string getMessage() { return this->message; }
    private:
        string message;
        Player player; // The player who picked up the card
};

class Advance : public Card {
    public:
        Advance(string location);
        void updateLocationIndex();
    private:
        string location;
        int locationIndex;
};

class AdvanceUtility : public Card {
    public:
        AdvanceUtility(int multiplier);
        int findNextUtility(Player player); // Find index of next utility
        Player findUtilityOwner(); // Find owner of next utility, NULL if no one owns it
    private:
        int multiplier; // The multiplier to replace tile multiplier
};

class AdvanceRailroad : public Card {
    public:
        AdvanceRailroad(int multiplier);
        int findNextRailroad(int currentLocation); // Find index of next railroad
        Player findRailroadOwner(); // Find owner of next railroad, NULL if no one owns it
    private:
        int multiplier; // What to multiply cost by
};

class BankPay : public Card {
    public:
        BankPay(int amount);
        void payPlayer(Player &player); // Add money from bank to player
    private:
        int amount;
};

class GetOutOfJail : public Card {
    public:
        GetOutOfJail();
    private:
};

class GoBackThree : public Card {
    public:
        GoBackThree();
        int getMove() { return this->move; }
    private:
        int move; // Player will move backwards 3 spaces
};

class GoToJail : public Card {
    public:
        GoToJail();
    private:
        int location; // Move player to jail tile
};

class Repairs : public Card {
    public:
        Repairs(int housePrice, int hotelPrice);
        int calculateCost(Player &player); // Calculate cost of repairs, each house pay $25, each hotel pay $100
    private:
        int housePrice;
        int hotelPrice;
};

class Fine : public Card {
    public:
        Fine(int amount);
    private:
        int amount;
};

class PayEachPlayer : public Card {
    public:
        PayEachPlayer(int amount);
        void payEachPlayer();
    private:
        int amount;
};

class FineEachPlayer : public Card {
    public:
        FineEachPlayer(int amount);
        void fineEachPlayer();
    private:
        int amount;
};


#endif