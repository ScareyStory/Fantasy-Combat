/**************************************************************************
** Program Name: Character.hpp
** Name:         Story Caplain
** Date:         02/06/19
** Description:  This is the implemntation file for the Character class.
**               It is the parent class in the Fantasy Combat Game
**************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>

class Character {

private:

/*
  int attack;
  int defense;
  int armor;
  int strength;
*/
protected:
  int attack;
  int defense;
  int armor;
  int strength;
public:

  Character(int, int, int, int);

  virtual int attacking() = 0;

  virtual int defending() = 0;

  int getAttack();

  int getDefense();

  int getArmor();

  int getStrength();
  
  void setAttack(int);

  void setDefense(int);

  int setArmor(int);

//  void setStrength(int, int, int);
  virtual void setStrength(int) = 0;

  virtual ~Character();

};
#endif
