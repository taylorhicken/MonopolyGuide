#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>

using namespace std;

class Tile {
    public:
        Tile() {};
        Tile(string propertyName, int id, int price, int mortgagePrice, int housePrice, int rent[]);
    private:
        string propertyName;
        int id;
        int price;
        int mortgagePrice;
        int housePrice;
        int rent[10]; // [Normal, Monopoly, 1 House, 2 House, 3 House, 4 House, Hotel, 2 Railroad, 3 Railroad, 4 Railroad] 

};

#endif