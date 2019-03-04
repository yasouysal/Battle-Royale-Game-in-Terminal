#include "Tracer.h"
#include "Entity.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Tracer::Tracer(uint id, int x, int y) : Player(id,x,y) {
	//this -> id = id;
	//(this -> coordinate).x = x;
	//(this -> coordinate).y = y;
	HP = 100;
}

Armor Tracer::getArmor() const{
	return BRICK;
}

Weapon Tracer::getWeapon() const{
	return SHOVEL;
}

std::vector<Move> Tracer::getPriorityList() const{
	return { UP, LEFT, DOWN, RIGHT, ATTACK };
}

const std::string Tracer::getFullName() const{
	//string s = strcat("Tracer", getBoardID());
	//return s;
	return "Tracer" + getBoardID();	
}


/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/