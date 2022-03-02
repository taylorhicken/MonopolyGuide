#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Board {
    public:
        Board(int numPlayers, Player firstPlayer);
        void createTiles();
    private:
        int numPlayers;
        Player currentPlayer;
        Tile tiles[1];
};

#endif