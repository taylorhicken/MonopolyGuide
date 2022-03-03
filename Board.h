#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "Card.h"
#include "Tile.h"
#include "Property.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int NUM_PROPERTIES = 28;
const int NUM_TILES = 40;
const int NUM_CARDS = 16;
const int MAX_PLAYERS = 6;

class Board {
    public:
        Board(int numPlayers, Player players[]);
        void createProperties(string propertyFile);
        void createTiles(string tileFile);
        void createCards(string inputFile, vector<Card> &deck);
        void setUpBoard();
    private:
        int numPlayers;
        int currentPlayer;
        Player players[MAX_PLAYERS];
        Property properties[NUM_PROPERTIES];
        Tile tiles[NUM_TILES];
        vector<Card> chanceDeck;
        vector<Card> communityChestDeck;
        const string propertyFile = "properties.txt";
        const string tileFile = "tiles.txt";
        string chanceFile = "chance.txt";
        string communityChestFile = "communitychest.txt";
};

#endif