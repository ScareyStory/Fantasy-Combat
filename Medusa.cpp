/**************************************************************************
** Program Name: Medusa.hpp
** Name:         Story Caplain
** Date:         02/07/19
** Description:  This is the .cpp file for the Medusa class.
**               It handles its specific attack and defend functions.
**************************************************************************/
#include <iostream>
#include <random>
#include "Medusa.hpp"

Medusa::Medusa(int atk, int def, int arm, int str) : 
  Character(atk,def,arm,str) {}

//returns a value 2 to 11, or glare activates and kills opponent
int Medusa::attacking() {

  int die1 = rand();
  int die2 = rand();

  //two six-sided dice means range is 2-12
  die1 = (die1 % 6) + 1;
  die2 = (die2 % 6) + 1;

  int roll = die1 + die2;

  if(roll < 12) {

    std::cout <<"\nMedusa attacks with a roll of "<< roll << std::endl;

    return roll;
  }
  else {

    std::cout << "\nMedusa locks eyes with its opponent..." << std::endl; 
    std::cout << "It is a stone cold glare!" << std::endl;
    //std::cout << "\nMedusa kills her opponent outright!\n";

    return 1000;
  }
}

//returns a value 2 to 12
int Medusa::defending() {

  int die = rand();

  //two six-sided dice means range is 2-12
  die = (die % 6) + 1;

  std::cout <<"\nMedusa defends with a roll of "<< die << std::endl;

  return die;

}

//Updates strength value
void Medusa::setStrength(int s) {

  strength -= s;

  if(strength <= 0 && strength > -100) {
    strength = 0;
    std::cout << "\nMedusa shrieks out in pain as she realizes her wound\n";
    std::cout << "is surely fatal. Her head of snakes slither away and  \n";
    std::cout << "leave her all alone. She feels her life leave her as  \n";
    std::cout << "she watches them slither away...\n";
  }
  else if(strength < -100) {
    strength = 0;
    std::cout << "\nMedusa feels her stare overcome by her counterpart\n";
    std::cout << "She felt her body begin to turn to stone, and her snakes";
    std::cout << "\nslither away in the hopes of avoiding the same fate...";
    std::cout << "\nAs she turns to stone her counterpart walks by and\n";
    std::cout << "pushes her over, shattering her stony corpse...\n";
  }
}
