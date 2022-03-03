#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <string>

using namespace std;

class Property {
    public:
        Property() {};
        Property(string name, int id, int price, int mortgagePrice, int housePrice, int rent[]);
        string getName() { return this->name; }
    private:
        string name;
        int id;
        int price;
        int mortgagePrice;
        int housePrice;
        int rent[10]; // [Normal, Monopoly, 1 House, 2 House, 3 House, 4 House, Hotel, 2 Railroad, 3 Railroad, 4 Railroad] 

};

#endif