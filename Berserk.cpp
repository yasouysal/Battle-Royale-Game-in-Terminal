#include "Berserk.h"
#include "Entity.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


Berserk::Berserk(uint id, int x, int y) : Player(id,x,y) {
	//this -> id = id;
	//(this -> coordinate).x = x;
	//(this -> coordinate).y = y;
	HP = 100;
}

Armor Berserk::getArmor() const{
	return WOODEN;
}

Weapon Berserk::getWeapon() const{
	return PISTOL;
}

std::vector<Move> Berserk::getPriorityList() const{
	return { ATTACK, UP, LEFT, DOWN, RIGHT };
}

const std::string Berserk::getFullName() const{
	//string s = strcat("Berserk", getBoardID());
	//return s;
	return "Berserk" + getBoardID();	
}


/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
