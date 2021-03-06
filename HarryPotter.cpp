/**************************************************************************
** Program Name: HarryPotter.hpp
** Name:         Story Caplain
** Date:         02/07/19
** Description:  This is the .cpp file for the HarryPotter class.
**               It handles its specific attack and defend functions.
**************************************************************************/
#include <iostream>
#include <random>
#include "HarryPotter.hpp"

HarryPotter::HarryPotter(int atk, int def, int arm, int str) : 
  Character(atk,def,arm,str) {}

//returns a value 2 to 12
int HarryPotter::attacking() {

  int die1 = rand();
  int die2 = rand();

  die1 = (die1 % 6) + 1;
  die2 = (die2 % 6) + 1;

  int roll = die1 + die2;

  std::cout <<"\nHarry Potter attacks with a roll of "<< roll << std::endl;

  return roll;
  
}

//returns a value 2 to 12
int HarryPotter::defending() {

  int die1 = rand();
  int die2 = rand();

  //two six-sided dice means range is 2-12
  die1 = (die1 % 6) + 1;
  die2 = (die2 % 6) + 1;

  int roll = die1 + die2;

  std::cout <<"\nHarry Potter defends with a roll of "<< roll << std::endl;

  return roll;

}

void HarryPotter::setStrength(int s) {

  strength -= s;

  if(strength <= 0 && strength > -100 && theBoyWhoLived==0) {
    strength = 0;
    std::cout << "\nHarry Potter is not so lucky this time...\n";
    std::cout << "He clutches his wounds and falls to the floor.\n";
    std::cout << "The most famous wizard to ever live has died..\n\n";
  }

  else if(strength < -100 && theBoyWhoLived==0) {
    strength = 0;
    std::cout << "\nHarry Potter feels his skin start to harden...\n";
    std::cout << "He tries to take a step but freezes before he can.\n";
    std::cout << "Medusa walks over and pushes the stone remains of\n";
    std::cout << "Harry Potter, he falls to floor and shatters...\n\n";
  }

  else if(strength <= 0 && theBoyWhoLived==1) {
    strength = 20;
    std::cout << "\nHarry Potter falls to the floor...\n";
    std::cout << "\n";
    std::cout << "But it is a miracle! Harry Potter comes back to life!\n";
    std::cout << "He has the twice the vitality he did before the battle!";
    std::cout << "\n\n";
    theBoyWhoLived--;
  }
} 
