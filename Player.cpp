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
void Player::movePlayer(string tileName) {
    int newLocation = board->getIndexFromTileName(tileName);

    if(passedGo(newLocation) && !jailed) {
        addMoney(200);
    }
}

void Player::addMoney(int amount) {
    this->balance += amount;
}