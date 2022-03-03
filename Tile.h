#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>
#include "Property.h"
#include "Card.h"

using namespace std;

class Tile {
    public:
        enum TileType {
            PROPERTY,
            TAX,
            DRAW_CARD,
            GO,
            JAIL,
            GO_TO_JAIL,
            FREE_PARKING
        };
        Tile();
        Tile(string tileName, Property property, TileType type); // PROPERTIES
        Tile(string tileName, int tax, TileType type); // INCOME TAX OR LUXURY TAX
        Tile(string tileName, TileType type); // CORNER TILES, COMMUNITY CHEST, OR CHANCE
        string getName() { return tileName; }
    private:
        string tileName;
        Property property;
        int tax;
        TileType type;
};

#endif