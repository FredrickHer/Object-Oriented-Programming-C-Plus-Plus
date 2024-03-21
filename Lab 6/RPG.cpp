// RPG.cpp

#include <iostream>
#include "RPG.h"
#include <cstdlib>
using namespace std;

RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = " slash";
    skills[1] = " parry";    
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
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
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

/**
 * @brief 
 * 
 * 
 *  @param opponent 
*/
void RPG::attack(RPG * opponent){
    //Implement brief
    // int new_health = (100-(20-5));
    int new_health = (*opponent).getHealth()-(strength - (*opponent).getDefense());
    (*opponent).updateHealth(new_health);
}

/**
 * @brief prompts the user to choose a skill and calls printAction() and atack()
 * 
 * @param opponent
 
*/
void RPG::useSkill(RPG * opponent){
   
   for(int i = 0; i < SKILL_SIZE; i++){
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }
    int chosen_skill_index;
    printf("Choose a skill to use: Enter 0 or 1\n");

    cin >> chosen_skill_index;

    string chosen_skill = skills[chosen_skill_index];

    printAction(chosen_skill, (*opponent));

    attack(opponent);
}
    
    

