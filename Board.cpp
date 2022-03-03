#include "Board.h"
string propertyFile = "properties.txt";
string tileFile = "tiles.txt";
string chanceFile = "chance.txt";
string communityChestFile = "communitychest.txt";

Board::Board(int numPlayers, Player players[]) {
    this->numPlayers = numPlayers;
    this->currentPlayer = 0;
    createProperties();
    createTiles();
}


/**
 * @brief Reads in card file and creates Card objects for each
 * 
 * @param inputFile - The file to read
 * @param deck - the card array to store cards in
 */
void createCards(string inputFile, vector<Card> &deck) {
    ifstream cardInput(inputFile);
    string type;
    cardInput >> type;
    if(type == "ADVANCE") {
        string location, message;
        cardInput >> location;
        getline(cardInput, message);
        Advance card(location);
        deck.push_back(card);
    } else if(type == "ADVANCE_RAILROAD") {
        int multiplier;
        string message;
        cardInput >> multiplier;
        getline(cardInput, message);
        AdvanceRailroad card(multiplier);
        deck.push_back(card);
    } else if(type == "ADVANCE_UTILITY") {
        int multiplier;
        string message;
        cardInput >> multiplier;
        getline(cardInput, message);
        AdvanceUtility card(multiplier);
        deck.push_back(card);
    } else if(type == "BANKPAY") {
        int amount;
        string message;
        cardInput >> amount;
        getline(cardInput, message);
        BankPay card(amount);
        deck.push_back(card);
    } else if(type == "GETOUTOFJAIL") {
        string message;
        getline(cardInput, message);
        GetOutOfJail card;
        deck.push_back(card);
    } else if(type == "GOBACKTHREE") {
        string message;
        getline(cardInput, message);
        GoBackThree card;
        deck.push_back(card);
    } else if(type == "GOTOJAIL") {
        string message;
        getline(cardInput, message);
        GoToJail card;
        deck.push_back(card);
    } else if(type == "REPAIRS") {
        int housePrice, hotelPrice;
        string message;
        cardInput >> housePrice;
        cardInput >> hotelPrice;
        getline(cardInput, message);
        Repairs card(housePrice, hotelPrice);
        deck.push_back(card);
    } else if(type == "FINE") {
        int amount;
        string message;
        cardInput >> amount;
        getline(cardInput, message);
        Fine card(amount);
        deck.push_back(card);
    } else if(type == "PAYEACHPLAYER") {
        int amount;
        string message;
        cardInput >> amount;
        getline(cardInput, message);
        PayEachPlayer card(amount);
        deck.push_back(card);
    } else if(type == "FINEEACHPLAYER") {
        int amount;
        string message;
        cardInput >> amount;
        getline(cardInput, message);
        FineEachPlayer card(amount);
        deck.push_back(card);
    }

}

/**
 * @brief Reads in property file and creates Property objects for each
 * 
 */
void Board::createProperties() {
    ifstream propertyInput(propertyFile);
    int columns;
     propertyInput >> columns;

    for(int r = 0; r < NUM_PROPERTIES; r++) {
        // Read input from file (Fix later)
        string name;
        propertyInput >> name;
        int id;
        int price;
        int mortgage;
        int house;
        int rent[10];
         propertyInput >> id;
         propertyInput >> price;
         propertyInput >> mortgage;
         propertyInput >> house;
         propertyInput >> rent[0];
         propertyInput >> rent[1];
         propertyInput >> rent[2];
         propertyInput >> rent[3];
         propertyInput >> rent[4];
         propertyInput >> rent[5];
         propertyInput >> rent[6];
         propertyInput >> rent[7];
         propertyInput >> rent[8];
         propertyInput >> rent[9];
        Property newProperty(name, id, price, mortgage, house, rent);
        this->properties[r] = newProperty;
    }
}

/**
 * @brief Reads in tile file and creates Tile objects for each
 * 
 */
void Board::createTiles() {
    ifstream tileInput(tileFile);
    for(int i = 0; i < NUM_TILES; i++) {
        string name;
        tileInput >> name;
        if(name == "GO") {
            Tile tile(name, Tile::GO);
            tiles[i] = tile;
        } else if(name == "JAIL") {
            Tile tile(name, Tile::JAIL);
            tiles[i] = tile;
        } else if(name == "FREEPARKING") {
            Tile tile(name, Tile::FREE_PARKING);
            tiles[i] = tile;
        } else if(name == "GOTOJAIL") {
            Tile tile(name, Tile::GO_TO_JAIL);
            tiles[i] = tile;
        } else if(name == "CHANCE" || name == "COMMUNITYCHEST") {
            Tile tile(name, Tile::DRAW_CARD);
            tiles[i] = tile;
        } else if(name == "INCOMETAX") {
            Tile tile(name, 200, Tile::TAX);
            tiles[i] = tile;
        } else if(name == "LUXURYTAX") {
            Tile tile(name, 100, Tile::TAX);
            tiles[i] = tile;
        } else {
            for(int j = 0; j < NUM_PROPERTIES; j++) {
                if(properties[j].getName() == name) {
                    Property property = properties[j];
                    Tile tile(name, property, Tile::PROPERTY);
                    tiles[i] = tile;
                    break;
                }
            }
        }
    }
}


