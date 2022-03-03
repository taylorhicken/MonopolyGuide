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

class Player;

const int NUM_PROPERTIES = 28;
const int NUM_TILES = 40;
const int NUM_CARDS = 16;
const int MAX_PLAYERS = 6;

class Board {
    public:
        void createProperties(string propertyFile);
        void createTiles(string tileFile);
        void createCards(string inputFile, vector<Card> &deck);
        void setUpBoard();
        static Board *getInstance() {
            if(!instance) {
                instance = new Board;
            }
            return instance;
        }
        int getIndexFromTileName(string name);
        void setNumPlayers(int numPlayers) { this->numPlayers = numPlayers; }
        void addPlayers(vector<Player> players);
    private:
        static Board *instance;
        Board();
        int numPlayers;
        int currentPlayer;
        vector<Player> players;
        Property properties[NUM_PROPERTIES];
        Tile tiles[NUM_TILES];
        vector<Card> chanceDeck;
        vector<Card> communityChestDeck;
        const string propertyFile = "properties.txt";
        const string tileFile = "tiles.txt";
        const string chanceFile = "chance.txt";
        const string communityChestFile = "communitychest.txt";
};

#endif