#include "Tile.h"

Tile::Tile() {

}

Tile::Tile(string tileName, Property property, TileType type) {
    this->tileName = tileName;
    this->property = property;
}

Tile::Tile(string tileName, int tax, TileType type) {
    this->tileName = tileName;
    this->tax = tax;
}

Tile::Tile(string tileName, TileType type) {
    this->tileName = tileName;
}