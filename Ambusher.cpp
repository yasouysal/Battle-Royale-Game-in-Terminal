#include "Ambusher.h"
#include "Entity.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Ambusher::Ambusher(uint id, int x, int y) : Player(id,x,y) {
	//this -> id = id;
	//(this -> coordinate).x = x;
	//(this -> coordinate).y = y;
	HP = 100;
}

Armor Ambusher::getArmor() const{
	return NOARMOR;
}

Weapon Ambusher::getWeapon() const{
	return SEMIAUTO;
}

std::vector<Move> Ambusher::getPriorityList() const{
	return { ATTACK };
}

const std::string Ambusher::getFullName() const{//buna bi bak
	//string s = strcat("Ambusher", getBoardID());
	//return s;
	return "Ambusher" + getBoardID();	
}


/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
