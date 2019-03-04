#include "Board.h"
#include "Coordinate.h"
#include "Entity.h"
#include "Player.h"
using namespace std;

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

Board::Board(uint boardSize, std::vector<Player *> *players) : boardSize(boardSize), players(players){
	currentRound = 1;
}

Board::~Board(){
	
}

uint Board::getSize() const{
	return boardSize;
}

bool Board::isCoordInBoard(const Coordinate& coord) const{
	int a = coord.x;
	int b = coord.y;
	if((a <= boardSize-1) && (b <= boardSize-1) && (a >= 0) && (b >= 0)) {
		return 1;
	}
	else{
		return 0;
	}
}


bool Board::isStormInCoord(const Coordinate &coord) const{//duzeltmek gerekebilir
	if(isCoordHill(coord)){
		return 0;
	}
	if(!isCoordInBoard(coord)){
		return 0;
	}
	int a = coord.x;
	int b = coord.y;
	if(a >(boardSize/2)){
		a = boardSize - a -1;
	}
	if(b >(boardSize/2)){
		b = boardSize - b -1;
	}
	int stormwidth = Entity::stormWidthForRound(currentRound);
	if( (a >= stormwidth) && (b >= stormwidth) ) {
		return 0;
	}
	else{
		return 1;
	}
}

void Board::updateStorm(uint currentRound){
	this -> currentRound = currentRound ;
}

bool Board::isCoordHill(const Coordinate& coord) const{
	int a = coord.x;
	int b = coord.y;
	int centercoord = (boardSize/2);
	if(a == centercoord && b == centercoord){
		return 1;
	}
	else{
		return 0;
	}
}


Player * Board::operator[](const Coordinate& coord) const{
	if(!isCoordInBoard(coord)){
		return NULL;
	}
	int a = coord.x;
	int b = coord.y;
	std::vector<Player*> myvector = *players;
	for(int round = 0; round < myvector.size(); round++){
		if((myvector[round] -> getCoord().x == coord.x) && (myvector[round] -> getCoord().y == coord.y) ){
			return myvector[round];
		}
	}
	return NULL;
}


Coordinate Board::calculateCoordWithMove(Move move, const Coordinate &coord) const{
	if(move == ATTACK || move == NOOP){
		return coord;
	}
	Coordinate notsurecoord = coord+move;
	
	std::vector<Player*> myvector = *players;
	for(int round = 0; round < myvector.size(); round++){
		if((myvector[round] -> getCoord().x == notsurecoord.x) && (myvector[round] -> getCoord().y == notsurecoord.y) ){
			return coord;
		}
	}
	int a = notsurecoord.x;
	int b = notsurecoord.y;
	if(a<0 || b <0 || a>boardSize-1 || b > boardSize-1){
		return coord;
	}

	return notsurecoord;
}


std::vector<Coordinate> Board::visibleCoordsFromCoord(const Coordinate &coord) const{
	if(!isCoordInBoard(coord)){
		return {};
	}
	std::vector<Coordinate> myvector = {};
	if((coord.y)-1 != -1){
		Coordinate upper(coord.x,(coord.y)-1);
		myvector.push_back(upper);
	}
	if((coord.y)+1 != boardSize){
		Coordinate lower(coord.x,(coord.y)+1);
		myvector.push_back(lower);
	}
	if((coord.x)-1 != -1){
		Coordinate lefter((coord.x)-1,coord.y);
		myvector.push_back(lefter);
	}
	if((coord.x)+1 != boardSize){
		Coordinate righter((coord.x)+1,coord.y);
		myvector.push_back(righter);
	}
	return myvector;
}

std::vector<Player *>* Board::getplayers() const{
	return players;
}