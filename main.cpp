/**************************************************************************
** Program Name: main.cpp
** Name:         Story Caplain
** Date:         02/08/19
** Description:  Plays a turn based combat game where die rolls determine
**               defense and offense.
***************************************************************************/
#include <iostream>
#include <string>
#include <random>
#include "startMenu.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

  int val = 1; //input validation

  cout << "\n\nIn this game two characters go head to head in combat.  \n";
  cout << "Player 1 and Player 2 choose usernames and character types. \n";
  cout << "Then each round each character rolls a die(s) to determine  \n";
  cout << "attack value and defense value. If a character's attack roll\n";
  cout << "exceeds the other character's defense roll. The difference  \n";
  cout << "is inflicted as damage to the defending character. Damage is\n";
  cout << "first deducted from armor value, if any, then from strength.\n";
  cout << "Once a character's strength reaches zero, they are dead and \n";
  cout << "the surviving character is declared victor.\n\n";

  //get player 1's name
  std::string name1 = " ";
  cout << "Player 1, what is your name?: ";
  cin  >> name1;
  while(val==1) {
    if(cin.fail() || name1.length() > 15) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\nOops! Invalid input." << endl;
      cout << "Enter a name 15 characters or less: ";
      cin  >> name1;
    }
    else if(!cin.fail()) {
      val = 0;
    }
  }
  cin.clear();
  cin.ignore(256, '\n');

  //reset val
  val = 1;
  
  //get player 2's name
  std::string name2 = " ";
  cout << "Player 2, what is your name?: ";
  cin  >> name2;
  while(val==1) {
    if(cin.fail() || name2.length() > 15) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\nOops! Invalid input." << endl;
      cout << "Enter a name 15 characters or less: ";
      cin  >> name2;
    }
    else if(!cin.fail()) {
      val = 0;
    }
  }
  cin.clear();
  cin.ignore(256, '\n');

  //for while loop
  bool playing = true;

  while(playing==true) {

    //For player 1's character choice
    int choice1 = 0;
    choice1 = startMenu(name1);
  
    //For player2's character choice
    int choice2 = 0;
    choice2 = startMenu(name2);
  
    Character * c1;
    Character * c2;

    switch(choice1) {

      case 1: 
        //c1 = &v1
        c1 = new Vampire(0,0,1,18);
        break;
      case 2:
        //c1 = &b1
        c1 = new Barbarian(0,0,0,12);
        break;
      case 3:
        //c1 = &bm1;
        c1 = new BlueMen(0,0,3,12);
        break;
      case 4:
        //c1 = &m1;
        c1 = new Medusa(0,0,3,8);
        break;
      case 5:
        //c1 = &hp1;
        c1 = new HarryPotter(0,0,0,10);
        break;
      default: cout << "\n\n 1: Error, default case reached\n\n";
    }
  
    switch(choice2) {

      case 1: 
        //c2 = &v2;
        c2 = new Vampire(0,0,1,18);
        break;
      case 2:
        //c2 = &b2;
        c2 = new Barbarian(0,0,0,12);
        break;
      case 3:
        //c2 = &bm2;
        c2 = new BlueMen(0,0,3,12);
        break;
      case 4:
        //c2 = &m2;
        c2 = new Medusa(0,0,3,8);
        break;
      case 5:
        //c2 = &hp2;
        c2 = new HarryPotter(0,0,0,10);
        break;
      default: cout << "\n\n 2: Error, default case reached\n\n";
    }
 
    for(int i=0; i<50; i++) {
      cout << "\n";
    }

    cout << "\nA coin is flipped to determine who goes first!\n";
    cout << "A heads means "<<name1<<" goes first\n";
    cout << "and a tails means "<<name2<<" goes first\n\n";

    int coin = rand();
    coin = coin % 2;

    if(coin==0) {
      cout << "It's a heads! "<<name1<<" goes first!\n";
    }
  
    else if(coin==1) {
      cout << "It's a tails! "<<name2<<" goes first!\n";
    }
  
    int round = 0;
    bool battling = true;
    
    int damage1 = 0;
    int damage2 = 0;

    while(battling==true) {
      if(coin==0) {
        round++;

        cout << "\nHit enter to begin round...\n";
        cin.clear();
        cin.ignore(256, '\n');

        cout << "\n\nIt is round "<<round<<"... Fight!\n\n";
        
        //attack1 holds the return value of c1's attacking function
        int attack1 = c1->attacking();
        c1->setAttack(attack1);

        //defend2 holds the return value of c2's defending function
        int defend2 = c2->defending();
        c2->setDefense(defend2);

        //damage holds the difference between c1's attack and c2's defend
        int damage1 = attack1 - defend2;

        //If attack exceeds defense
        if(damage1 > 0) {

          //excess holds the amount of damage not caught by armor
          int excess = c2->setArmor(damage1);
          
          //if damage exceeds armor, reduce strength by excess
          c2->setStrength(excess);
          
          //if Player 2's character is killed
          if(c2->getStrength() <= 0) {
            cout << "\n\n";
            cout <<name2<<"'s character is dead!\n";
            battling = false;
          }
        }
        //else if defense exceeds attck
        else{
          
          //If Medusa locked eyes with a charming vampire
          if(attack1==1000 && defend2==1000) {
            cout << "\nThe Vampire's charming eyes are unaffected by"
                 << " Medusa's glare!" << endl;
          }
          //If defense exceeds or equals attack
          else {
            cout << "\n\n";
            cout <<name2<<"'s character took no damage!\n";
          }
        }

        //Now Player 2 attacks
        cout << endl;
        if(c2->getStrength() > 0) {

          //attack2 holds the return value of c2's attacking function
          int attack2 = c2->attacking();
          c2->setAttack(attack2);

          //defend1 holds the return value of c1's defending function
          int defend1 = c1->defending();
          c1->setDefense(defend1);

          //damage holds the difference between c2's attack and c1's defend
          int damage2 = attack2 - defend1;

          //If attack exceeds defense
          if(damage2 > 0) {

            //excess holds the amount of damage not caught by armor
            int excess = c1->setArmor(damage2);
            
            //if damage exceeds armor, reduce strength by excess
            c1->setStrength(excess);
            
            //if Player 1's character is killed
            if(c1->getStrength() <= 0) {
              cout << "\n\n";
              cout <<name1<<"'s character is dead!\n";
              battling = false;
            }
          }
          //else if defense exceeds attck
          else{
            
            //If Medusa locked eyes with a charming vampire
            if(attack2==1000 && defend1==1000) {
              cout << "\nThe Vampire's charming eyes are unaffected by"
                   << " Medusa's glare!" << endl;
            }
            //If defense exceeds or equals attack
            else {
              cout << "\n\n";
              cout <<name1<<"'s character took no damage!\n";
            }
          }
        } 
      }//coin == 0

      if(coin==1) {
        round++;

        cout << "\nHit enter to begin round...\n";
        cin.clear();
        cin.ignore(256, '\n');

        cout << "\n\nIt is round "<<round<<"... Fight!\n\n";
        
        //attack2 holds the return value of c2's attacking function
        int attack2 = c2->attacking();
        c2->setAttack(attack2);

        //defend1 holds the return value of c1's defending function
        int defend1 = c1->defending();
        c1->setDefense(defend1);

        //damage holds the difference between c2's attack and c1's defend
        int damage2 = attack2 - defend1;

        //If attack exceeds defense
        if(damage2 > 0) {

          //excess holds the amount of damage not caught by armor
          int excess = c1->setArmor(damage2);
          
          //if damage exceeds armor, reduce strength by excess
          c1->setStrength(excess);
          
          //if Player 1's character is killed
          if(c1->getStrength() <= 0) {
            cout << "\n\n";
            cout <<name1<<"'s character is dead!\n";
            battling = false;
          }
        }
        //else if defense exceeds attck
        else{
          
          //If Medusa locked eyes with a charming vampire
          if(attack2==1000 && defend1==1000) {
            cout << "\nThe Vampire's charming eyes are unaffected by"
                 << " Medusa's glare!" << endl;
          }
          //If defense exceeds or equals attack
          else {
            cout << "\n\n";
            cout <<name1<<"'s character took no damage!\n";
          }
        }

        //Now Player 1 attacks
        cout << endl;
        if(c1->getStrength() > 0) {

          //attack1 holds the return value of c1's attacking function
          int attack1 = c1->attacking();
          c1->setAttack(attack1);

          //defend2 holds the return value of c2's defending function
          int defend2 = c2->defending();
          c2->setDefense(defend2);

          //damage holds the difference between c1's attack and c2's defend
          int damage1 = attack1 - defend2;

          //If attack exceeds defense
          if(damage1 > 0) {

            //excess holds the amount of damage not caught by armor
            int excess = c2->setArmor(damage1);
            
            //if damage exceeds armor, reduce strength by excess
            c2->setStrength(excess);
            
            //if Player 2's character is killed
            if(c2->getStrength() <= 0) {
              cout << "\n\n";
              cout <<name2<<"'s character is dead!\n";
              battling = false;
            }
          }
          //else if defense exceeds attck
          else{
            
            //If Medusa locked eyes with a charming vampire
            if(attack1==1000 && defend2==1000) {
              cout << "\nThe Vampire's charming eyes are unaffected by"
                   << " Medusa's glare!" << endl;
            }
            //If defense exceeds or equals attack
            else {
              cout << "\n\n";
              cout <<name2<<"'s character took no damage!\n";
            }
          }
        } 
      }//coin==1

      cout << "\n\nHit enter for detailed round statistics...";
      cin.clear();
      cin.ignore(256, '\n');

      //Make space
      for(int i=0; i<50; i++) { cout << "\n"; }

      //Print out detailed round statistics
      cout << "\n\n";
      
      cout << "Name:\t\t" << name1;
           
      //makes proper amount of space 
       for(int i=(name1.length()); i<16; i++) {cout<<" ";}
           
      cout << name2;
      cout << endl;
    
      //Output attack based on how much attack
      if(c1->getAttack() > 100) {
        cout << "Attack:\t\t" << "Glare!" << "\t\t" << c2->getAttack();
        cout << endl;
      } 
      else if(c2->getAttack() > 100) {
        cout << "Attack:\t\t" << c1->getAttack() << "\t\t" << "Glare!";
        cout << endl;
      }
      else { 
        cout << "Attack:\t\t" << c1->getAttack() <<"\t\t"<< c2->getAttack();
        cout << endl;
      }
        
      //Output defense based on how much defense
      if(c1->getDefense() > 100) {
        cout << "Defense:\t" << "Charm!" << "\t\t" << c2->getDefense();
        cout << endl;
      } 
      else if(c2->getDefense() > 100) {
        cout << "Defense:\t" << c1->getDefense() << "\t\t" << "Charm!";
        cout << endl;
      }
      else { 
        cout << "Defense:\t" << c1->getDefense() <<"\t\t"<<c2->getDefense();
        cout << endl;
      }
     
      //make sure damage taken isn't printed as a negative number 
      if(c2->getAttack() - c1->getDefense() < 0) {
        damage1 = 0;
      }
      else {
        damage1 = c2->getAttack() - c1->getDefense();
      }
      
      //make sure damage taken isn't printed as a negative number 
      if(c1->getAttack() - c2->getDefense() < 0) {
        damage2 = 0;
      }
      else {
        damage2 = c1->getAttack() - c2->getDefense();
      }

      //Output rest of statistics
      if(damage1 > 100) {
        cout << "Damage Taken:\t" << "Glared!" << "\t\t" << damage2;
        cout << endl;
      }
      else if(damage2 > 100) {
        cout << "Damage Taken:\t" << damage1 << "\t\t" << "Glared!";
        cout << endl;
      }
      else {
        cout << "Damage Taken:\t" << damage1 << "\t\t" << damage2;
        cout << endl;
      }  

      cout << "Armor:\t\t"<< c1->getArmor()<<"\t\t"<< c2->getArmor();
      cout << endl;
      
      cout << "Strength:\t"<< c1->getStrength()<<"\t\t"<< c2->getStrength();
      cout << endl;

      //check if characters are alive
      int alive1 = c1->getStrength();
      int alive2 = c2->getStrength();

      if(alive1<=0) {
        cout << "\n"<<name1<<"'s character is defeated!\n";
      }
      else if(alive2<=0) {
        cout << "\n"<<name2<<"'s character is defeated!\n";
      }

      if(alive1<=0 || alive2<=0) {
        char again;
        cout << "\nWould you like to play again?\n";
        cout << "Enter p to play again or anything else to quit: ";
        cin  >> again;
        if(cin.fail() || (again != 'p' && again != 'P')) {
          playing = false;
        }
        else if(again == 'p' || again == 'P') {
          playing = true;
        }
      }
    }//battling loop

    //free memory
    delete c1;
    delete c2;

  }//playing loop
  
  return 0;
}
