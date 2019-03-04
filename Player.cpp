#include "Player.h"
#include <iostream>
#include <stdio.h>  
#include <string.h>
#include <algorithm>
#include <sstream>
#include "Coordinate.h"
#include "Entity.h"
using namespace std;

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/


Player::Player(uint id, int x, int y) : id(id), coordinate(x,y){
	//this -> id = id;
	//(this -> coordinate).x = x;
	//(this -> coordinate).y = y;
}

uint Player::getID() const{
	return id;
}

const Coordinate& Player::getCoord() const{
	return coordinate;
}

int Player::getHP() const{
	return HP;
}

std::string Player::getBoardID() const{
	if(id >= 10){
		return std::to_string(id);
	}
	else{
		std::string s = to_string(id);
		//return strcat("0",s);
		return "0" + s;
	}
}

Player::~Player(){
	
}

bool Player::isDead() const{
	if(HP <= 0){
		return 1;
	}
	else{
		return 0;
	}
}


void Player::executeMove(Move move){
	if(move == NOOP || move == ATTACK){
		return;
	}

	this -> coordinate = coordinate + move;

	if(move == UP) {
		cout << getFullName() << "(" << HP << ") " << "moved" << " UP." << "\n"; 
	}

	else if(move == DOWN) {
		cout << getFullName() << "(" << HP << ") " << "moved" << " DOWN." << "\n";
	}

	else if(move == RIGHT) {
		cout << getFullName() << "(" << HP << ") " << "moved" << " RIGHT." << "\n";
	}

	else if(move == LEFT) {
		cout << getFullName() << "(" << HP << ") "  << "moved" << " LEFT." << "\n";
	}

}

bool Player::attackTo(Player *player){//sifir olma durumunun ekle ve can eksiye dusunce yazdirma
	if(player -> HP <= 0){
		if(HP <= 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	

	if(getFullName() != player -> getFullName()){
		cout << getFullName() << "(" << HP << ") " << "ATTACKED " << (player -> getFullName()) << "(" << (player -> getHP()) << ")" << "! " << "(" << "-" << (Entity::damageForWeapon(this -> getWeapon() ) - Entity::damageReductionForArmor(player -> getArmor() ) ) << ")" << "\n";

		player -> HP -= max( (Entity::damageForWeapon(this -> getWeapon() ) - Entity::damageReductionForArmor(player -> getArmor() ) ), 0);

	}
	

	if(player ->HP <= 0){
		return 1;
	}
	else{
		return 0;
	}


}

void Player::setHP(uint newhp){
	HP = newhp;
}