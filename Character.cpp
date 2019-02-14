/**************************************************************************
** Program Name: Character.cpp
** Name:         Story Caplain
** Date:         02/06/19
** Description:  This is the .cpp file for the Character class.
**               It is the parent class in the Fantasy Combat Game
**************************************************************************/
#include <iostream>
#include "Character.hpp"

//Pure Virtual Function
//virtual int attacking() = 0;

//Pure Virtual Function
//virtual int defending() = 0;

Character::Character(int atk, int def, int arm, int str) : attack(atk), defense(def),  armor(arm), strength(str) {}

int Character::getAttack() { return attack; }

void Character::setAttack(int a) { attack = a; }


int Character::getDefense() { return defense; }

void Character::setDefense(int d) {defense = d;}


int Character::getArmor() { return armor; }

int Character::setArmor(int damage) { 
 
  //If attack doesn't destroy armor, reduce armor 
  if(armor >= damage) {
    armor -= damage;
    return 0;
  }
  //Else if attack destroys armor, or no armor, return damage
  //to be deducted from strength
  else {
    int excess = damage - armor;
    armor = 0;
    return excess;
  }
}


int Character::getStrength() { return strength; }

/*
void Character::setStrength(int s, int choice, int check) { 
  
  strength -= s;

  if(strength < 0) {
    strength = 0;
  }
}
*/

//virtual destructor
Character::~Character() {}



