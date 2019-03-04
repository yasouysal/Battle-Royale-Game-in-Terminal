#include "Pacifist.h"
#include "Entity.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Pacifist::Pacifist(uint id, int x, int y) :Player(id,x,y){
	//this -> id = id;
	//(this -> coordinate).x = x;
	//(this -> coordinate).y = y;
	HP = 100;
}

Armor Pacifist::getArmor() const{
	return METAL;
}

Weapon Pacifist::getWeapon() const{
	return NOWEAPON;
}

std::vector<Move> Pacifist::getPriorityList() const{
	return { UP, LEFT, DOWN, RIGHT };
}

const std::string Pacifist::getFullName() const{
	//string s = strcat("Pacifist", getBoardID());
	//return s;
	return "Pacifist" + getBoardID();	
}

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/