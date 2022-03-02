#include "Tile.h"


Tile::Tile(string propertyName, int id, int price, int mortgagePrice, int housePrice, int rent[]) {
    this->propertyName = propertyName;
    this->id = id;
    this->price = price;
    this->mortgagePrice = mortgagePrice;
    this->housePrice = housePrice;
    for(int i = 0; i < 10; i++) {
        this->rent[i] = rent[i];
    }
}