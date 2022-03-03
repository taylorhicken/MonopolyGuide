#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
    public:
        Card();
        bool checkPassGo(); // Check if the player will pass go
        void payBank(int amount); // Remove money from players account
        void setMessage(string message) { this->message = message; }
        string getMessage() { return this->message; }
    private:
        string message;
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
        int findNextUtility(); // Find index of next utility
    private:
        int multiplier; // The multiplier to replace tile multiplier
};

class AdvanceRailroad : public Card {
    public:
        AdvanceRailroad(int multiplier);
        int findNextRailroad(); // Find index of next railroad
    private:
        int multiplier; // What to multiply cost by
};

class BankPay : public Card {
    public:
        BankPay(int amount);
        void payPlayer(); // Add money from bank to player
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
        int locationIndex; // Move player to jail tile
};

class Repairs : public Card {
    public:
        Repairs(int housePrice, int hotelPrice);
        int calculateCost(); // Calculate cost of repairs
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