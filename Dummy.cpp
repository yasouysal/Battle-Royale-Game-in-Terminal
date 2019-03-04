#include "Dummy.h"
#include "Entity.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Dummy::Dummy(uint id, int x, int y) : Player(id,x,y) {
	//this -> id = id;
	//(this -> coordinate).x = x;
	//(this -> coordinate).y = y;
	HP = 1000;
}

Armor Dummy::getArmor() const{
	return NOARMOR;
}

Weapon Dummy::getWeapon() const{
	return NOWEAPON;
}

std::vector<Move> Dummy::getPriorityList() const{
	return { NOOP };
}

const std::string Dummy::getFullName() const{
	//string s = strcat("Dummy", getBoardID());
	//return s;
	return "Dummy" + getBoardID();	
}


/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/