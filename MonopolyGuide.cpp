#include <stdio.h>
#include "Board.h"
#include "Player.h"

using namespace std;

int main() {
    cout << "Welcome to Monopoly Guide" << endl;
    // Get number of players
    int numPlayers = MAX_PLAYERS + 1;
    while(numPlayers > MAX_PLAYERS) {
        cout << "How many players will be playing?" << endl;
        cin >> numPlayers;
    }

    // Create each player
    Player players[numPlayers];
    bool setYou = false;
    for(int i = 0; i < numPlayers; i++) {
        cout << "What is the name of player " << i+1 << "?" << endl;
        string name;
        cin >> name;
        Player player(name);
        if(!setYou) {
            cout << "Is this player YOU? (Y/N)" << endl;
            char YON = 'O';
            while(YON != 'Y' && YON != 'N') {
                cin >> YON;
            }
            if(YON == 'Y') {
                player.setYou();
                setYou = true;
            }
        }
        players[i] = player;

    }
    cout << "PLAYERS CREATED" << endl;
    Board *board = board->getInstance(); // Initialize singleton instance
    board->setNumPlayers(numPlayers);
    cout << "BOARD INITIALIZED" << endl;



    return 0;
}