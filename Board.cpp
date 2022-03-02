#include "Board.h"
string tileFile = "tiles.txt";

Board::Board(int numPlayers, Player firstPlayer) {
    this->numPlayers = numPlayers;
    this->currentPlayer = firstPlayer;
}

/**
 * @brief Reads in tile file and creates Tile objects for each
 * 
 */
void Board::createTiles() {
    ifstream tileInput(tileFile);
    int rows;
    int columns;
    tileInput >> rows;
    tileInput >> columns;

    for(int r = 0; r < rows; r++) {
        // Read input from file
        string row;
        getline(tileInput, row);
        // Parse rows
        string parsedRow[columns];
        int columnCount = 0;
        for(int i = 0; i < row.length(); i++) {
            if(row[i] != ',') {
                parsedRow[columnCount] += row[i];
            } else {
                columnCount++;
            }
        } 
        // Create rent array
        int rent[10] = {
            stoi(parsedRow[5]), 
            stoi(parsedRow[6]), 
            stoi(parsedRow[7]), 
            stoi(parsedRow[8]), 
            stoi(parsedRow[9]), 
            stoi(parsedRow[10]), 
            stoi(parsedRow[11]), 
            stoi(parsedRow[12]), 
            stoi(parsedRow[13]), 
            stoi(parsedRow[14])
        };
        Tile newTile(parsedRow[0], stoi(parsedRow[1]), stoi(parsedRow[2]), stoi(parsedRow[3]), stoi(parsedRow[4]), rent);
    }
}


