#include <iostream>
#include "RPG.h"

using namespace std;

/**
 * @brief Prints both player's name and their health.
 * Example Output for name wiz NPC
 * Wiz health: 75 NPC health: 100\n
 * 
 * @param player1
 * @param player2
*/
void displayStats(RPG player1, RPG player2){
cout << player1.getName() << "health: " << player1.getHealth() << " ";
cout << player2.getName() << "health: " << player2.getHealth() << endl;

}

/**
 * @brief 
 * 
 * @param player1
 * @param player2 
*/
void displayEnd(RPG player1, RPG player2){ 
    if (player1.isAlive()){
        cout << player1.getName() << " defeated " << player2.getName() << "Good game! :)" << endl; }
    else{
        cout << player2.getName() << " defeated " << player1.getName() << "Good game! :)" << endl;
    }

}

/**
 * @brief
*/
void gameLoop(RPG * player1, RPG *player2){
    while((*player1).isAlive() & (*player2).isAlive()){
        displayStats((*player1), (*player2));
        cout << (*player1).getName() << " it's your turn \n"  << endl;
        (*player1).useSkill(player2);
        cout << "-------------------------------------\n" << endl;

        displayStats((*player1), (*player2));
        cout << (*player2).getName() << " it's your turn \n" << endl;
        (*player2).useSkill(player1);
        cout << "-------------------------------------\n" << endl;
    }

}

int main()
{
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 =RPG();

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;
}