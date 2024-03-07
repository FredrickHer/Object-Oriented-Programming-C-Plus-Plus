// RPG.cpp

#include "RPG.h"
#include <cstdlib>
using namespace std;

RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry";    
}

RPG:: RPG(string inputName, int inputHealth, int inputStrength, int inputDefense, string inputType){
    name = inputName;
    health = inputHealth;
    strength = inputStrength;
    defense = inputDefense;
    type = inputType;
    setSkills();
}

/**
 * @brief sets the skills based on the RPG's role
 * 
*/
void RPG::setSkills(){
    if(type == "mage"){
        skills [0] = "fire";
        skills [1] = "thunder";
    } else if (type == "thief"){
        skills [0] = "pilfer";
        skills [1] = "jab";
    } else if (type == "archer"){
        skills [0] = "parry";
        skills [1] = "crossbow_attack";
    } else {
        skills [0] = "slash";
        skills [1] = "parry";
    }

 }

/**
 * @brief Prints along the lines of NAME used SKILL on OPPENENT 
 * 
 * @param skill 
 * @param oppenent
*/
void RPG::printAction(string skill, RPG opponent){
    printf("%s used %s\n", name.c_str(), opponent.getName().c_str());
    }
/**
 * @brief prints along the lines of Name used skill 
 * 
 * @param new_health
*/
void RPG:: updateHealth(int new_health){
    health = new_health;
}


/**
 * @brief returns whether health is greater then 0 
 * 
 * @return true
 * @return false
*/
bool RPG:: isAlive() const{
    return health > 0;
}

/**
 * @brief 
 * 
 * @return int 
*/
string RPG:: getName() const{
    return name;
}

/**
 * @brief 
 * 
 * @return int
*/
int RPG::getHealth() const{
    return health;
}

/**
 * @brief 
 * 
 * @return int
*/
int RPG::getStrength() const{
    return strength;
}

/**
 * @brief 
 * 
 * @return int
*/
int RPG::getDefense() const{
    return defense;
}


