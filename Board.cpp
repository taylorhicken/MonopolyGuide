#include "Board.h"

Board::Board() {
    this->currentPlayer = 0;
    setUpBoard();
}

void Board::setUpBoard() {
    createProperties(propertyFile);
    createTiles(tileFile);
    createCards(chanceFile, chanceDeck);
    createCards(communityChestFile, communityChestDeck);
}

// Initialize pointer to zero so that it can be initialized in first call to getInstance
Board *Board::instance = 0;


/**
 * @brief Reads in card file and creates Card objects for each
 * 
 * @param inputFile - The file to read
 */
void Board::createCards(string inputFile, vector<Card> &deck) {
    ifstream cardInput(inputFile);
    string type;
    for(int i = 0; i < NUM_CARDS; i++) {
        cardInput >> type;
        if(type == "ADVANCE") {
            string location, message;
            cardInput >> location;
            getline(cardInput, message);
            Advance card(location);
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "ADVANCE_RAILROAD") {
            int multiplier;
            string message;
            cardInput >> multiplier;
            getline(cardInput, message);
            AdvanceRailroad card(multiplier);
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "ADVANCE_UTILITY") {
            int multiplier;
            string message;
            cardInput >> multiplier;
            getline(cardInput, message);
            AdvanceUtility card(multiplier);
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "BANKPAY") {
            int amount;
            string message;
            cardInput >> amount;
            getline(cardInput, message);
            BankPay card(amount);
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "GETOUTOFJAIL") {
            string message;
            getline(cardInput, message);
            GetOutOfJail card;
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "GOBACKTHREE") {
            string message;
            getline(cardInput, message);
            GoBackThree card;
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "GOTOJAIL") {
            string message;
            getline(cardInput, message);
            GoToJail card;
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "REPAIRS") {
            int housePrice, hotelPrice;
            string message;
            cardInput >> housePrice;
            cardInput >> hotelPrice;
            getline(cardInput, message);
            Repairs card(housePrice, hotelPrice);
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "FINE") {
            int amount;
            string message;
            cardInput >> amount;
            getline(cardInput, message);
            Fine card(amount);
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "PAYEACHPLAYER") {
            int amount;
            string message;
            cardInput >> amount;
            getline(cardInput, message);
            PayEachPlayer card(amount);
            card.setMessage(message);
            deck.push_back(card);
        } else if(type == "FINEEACHPLAYER") {
            int amount;
            string message;
            cardInput >> amount;
            getline(cardInput, message);
            FineEachPlayer card(amount);
            card.setMessage(message);
            deck.push_back(card);
        }
    }
}

/**
 * @brief Reads in property file and creates Property objects for each
 * 
 */
void Board::createProperties(string propertyFile) {
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
void Board::createTiles(string tileFile) {
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


