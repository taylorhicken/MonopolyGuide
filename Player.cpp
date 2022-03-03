#include "Player.h"

Player::Player() {
    this->name = "NO NAME";
    this->you = false;
    this->balance = 2000;
    this->currentLocation = 0;
    this->jailed = false;
    this->getOutOfJail = 0;
    board = board->getInstance();
}

Player::Player(string name) {
    this->name = name;
    this->you = false;
    this->balance = 2000;
    this->currentLocation = 0;
    this->jailed = false;
    this->getOutOfJail = 0;
    board = board->getInstance();
}

/**
 * @brief Mark the player as "YOU" i.e. the person trying to use MonopolyGuide
 * 
 */
void Player::setYou() {
    this->you = true;
}

/**
 * @brief Check if the player will pass go when moving to the new location
 * 
 * @param newLocation - The index of the new location
 * @return true - The player did pass go
 * @return false - The player did NOT pass go
 */
bool Player::passedGo(int newLocation) {
    if(newLocation < this->currentLocation) {
        return true;
    } 
    return false;
}

/**
 * @brief Update the players location with new tile index
 * 
 * @param tileName - Uppercase no space tile name
 */
void Player::movePlayerTo(string tileName) {
    int newLocation = board->getIndexFromTileName(tileName);

    if(newLocation == 0) {
        updateMoney(400); // Collect $400 salary
    } else if(passedGo(newLocation) && !jailed) {
        updateMoney(200); // Collect $200 salary
    }
    this->currentLocation = newLocation;
}

/**
 * @brief Move player ahead X spaces
 * 
 * @param spaces - the number of spaces to move forward
 */
void Player::movePlayerXSpaces(int spaces) {
    int newLocation = (this->currentLocation + spaces) % NUM_TILES;
    if(newLocation == 0) {
        updateMoney(400); // Collect $400 salary
    } else if(passedGo(newLocation) && !jailed) {
        updateMoney(200); // Collect $200 salary
    }
    this->currentLocation = newLocation;
}

/**
 * @brief Update the player's balance
 * 
 * @param amount The amount to change (positive for add, negative for subtract)
 */
void Player::updateMoney(int amount) {
    this->balance += amount;
}