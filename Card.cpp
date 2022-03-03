#include "Card.h"
using namespace std;


Card::Card() {
    
}

bool checkPassGo() {
    // TODO
    return false;
}

void payBank(int amount) {
    // TODO    
}

/**
 * @brief Construct a new Advance:: Advance object
 * 
 * @param location 
 */
Advance::Advance(string location) {
    this->location = location;
    updateLocationIndex();
}

void Advance::updateLocationIndex() {
    // TODO
}

/**
 * @brief Construct a new Advance Utility:: Advance Utility object
 * 
 * @param multiplier 
 */
AdvanceUtility::AdvanceUtility(int multiplier) {
    this->multiplier = multiplier;
}

int AdvanceUtility::findNextUtility() {
    // TODO
    return 0;
}

/**
 * @brief Construct a new Advance Railroad:: Advance Railroad object
 * 
 * @param multiplier 
 */
AdvanceRailroad::AdvanceRailroad(int multiplier) {
    this->multiplier = multiplier;
}

int AdvanceRailroad::findNextRailroad() {
    // TODO
    return 0;
}


/**
 * @brief Construct a new Bank Pay:: Bank Pay object
 * 
 * @param amount 
 */
BankPay::BankPay(int amount) {
    this->amount = amount;

}

void BankPay::payPlayer() {
    // TODO
}

/**
 * @brief Get the Out Of Jail:: Get Out Of Jail object
 * 
 */
GetOutOfJail::GetOutOfJail() {

}

/**
 * @brief Construct a new Go Back Three:: Go Back Three object
 * 
 */
GoBackThree::GoBackThree() {
    this->move = -3;
}

/**
 * @brief Construct a new Go To Jail:: Go To Jail object
 * 
 */
GoToJail::GoToJail() {
    this->locationIndex = 10; // JAIL tile at index 10
}

/**
 * @brief Construct a new Repairs:: Repairs object
 * 
 * @param housePrice 
 * @param hotelPrice 
 */
Repairs::Repairs(int housePrice, int hotelPrice) {
    this->housePrice = housePrice;
    this->hotelPrice = hotelPrice;
}

int Repairs::calculateCost() {
    // TODO
    return 0;
}

/**
 * @brief Construct a new Fine:: Fine object
 * 
 * @param amount 
 */
Fine::Fine(int amount) {
    this->amount = amount;
}

/**
 * @brief Construct a new Pay Each Player:: Pay Each Player object
 * 
 * @param amount 
 */
PayEachPlayer::PayEachPlayer(int amount) {
    this->amount = amount;
}

void PayEachPlayer::payEachPlayer() {
    // TODO
}

FineEachPlayer::FineEachPlayer(int amount) {
    this->amount = amount;
}

void FineEachPlayer::fineEachPlayer() {
    // TODO
}

