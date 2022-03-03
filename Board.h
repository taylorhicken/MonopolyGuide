#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "Tile.h"
#include "Property.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUM_PROPERTIES = 28;
const int NUM_TILES = 40;
const int MAX_PLAYERS = 6;

class Board {
    public:
        Board(int numPlayers, Player players[]);
        void createProperties();
        void createTiles();
    private:
        int numPlayers;
        int currentPlayer;
        Player players[MAX_PLAYERS];
        Property properties[NUM_PROPERTIES];
        Tile tiles[NUM_TILES];
};

#endif