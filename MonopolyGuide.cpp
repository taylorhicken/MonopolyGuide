#include <stdio.h>
#include "Board.h"
#include "Player.h"

using namespace std;

void getStartingConditions();


int main() {
    Player player1;
    Board board(4, player1);
    board.createTiles();


    return 0;
}

void getStartingConditions() {

}