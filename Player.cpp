#include "Player.h"

Player::Player() {
    this->name = "NO NAME";
    this->you = false;
    this->balance = 2000;
    this->currentLocation = 0;
    this->jailed = false;
}

Player::Player(string name) {
    this->name = name;
    this->you = false;
    this->balance = 2000;
    this->currentLocation = 0;
    this->jailed = false;
}

void Player::setYou() {
    this->you = true;
}