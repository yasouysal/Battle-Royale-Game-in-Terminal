#include "GameEngine.h"
#include "Player.h"
#include "Board.h"
#include "GameParser.h"
#include "Entity.h"
#include <stdio.h>
#include <iostream>
#include "Coordinate.h"
#include <vector>
#include <algorithm>
using namespace std;

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

GameEngine::GameEngine(uint boardSize, std::vector<Player *> *players) : board(Board(boardSize,players)){
	//board = Board::Board(boardSize,players);
	currentRound = 0;
	vectorsize = players->size();
}


GameEngine::~GameEngine(){
	std::vector<Player *>* players = board.getplayers();
	for(Player *player : *players){
	    delete player;
	}
	players->clear();
	delete players;
}

const Board& GameEngine::getBoard() const{
	return board;
}


Player* GameEngine::operator[](uint id) const{
	std::vector<Player *>* players = board.getplayers();
	for(int i=0; i<(*players).size();i++){
		if((*players)[i]->getID() == id){
			return (*players)[i];
		}
	}
	return NULL;
}

bool GameEngine::isFinished() const{
	std::vector<Player *>* players = board.getplayers();
	if( (players->size() ==0 ) || ((players->size() == 1) && board.isCoordHill(((*players)[0])->getCoord()))) {
		return 1;
	}
	else{
		return 0;
	}
}


void GameEngine::takeTurn(){
	currentRound++;
	board.updateStorm(currentRound);
	std::vector<Player *>* players = board.getplayers();

	sort( players->begin(), players->end(), sortcalculator );
	
	cout << "-- START ROUND " << currentRound << " --" << endl;
	for(int i=0; i<vectorsize;i++){
		Player* currentplayer = (*players)[i];
		int currentplayerindex = vectorindexfinder(players,currentplayer);
		int currentID = ((*players)[i])->getID();
		takeTurnForPlayer(currentID);
		int lateplayerindex = vectorindexfinder(players,currentplayer);
		if(lateplayerindex == -1 || lateplayerindex < currentplayerindex){
			i--;
		}

	}
	cout << "-- END ROUND " << currentRound << " --" << endl;

}


Move GameEngine::takeTurnForPlayer(uint playerID){
	std::vector<Player *>* players = board.getplayers();
	Player* selectedone = this->operator[](playerID);
	if(selectedone == NULL){
		return NOOP;
	}
	std::vector<Move> selectedoneslist = selectedone->getPriorityList();
	Coordinate selectedonescoords = selectedone->getCoord();
	std::vector<Coordinate> selectedonevisiblecoords = board.visibleCoordsFromCoord(selectedonescoords);
	if(board.isStormInCoord(selectedonescoords)){
		uint stormdamage = Entity::stormDamageForRound(currentRound);
		cout << selectedone->getFullName() << "(" << selectedone->getHP() << ") is STORMED! (-" << stormdamage << ")" << endl;
		selectedone->setHP(selectedone->getHP() - stormdamage);
		if(selectedone->isDead()){
			cout << selectedone->getFullName() << "(" << selectedone->getHP() << ") DIED." << endl;
			for(int j = 0; j< players->size();j++){
				if((*players)[j] == selectedone){
					players->erase(players->begin()+j);
					vectorsize--;
					delete selectedone;
				}
			}
			return NOOP;
		}
	}
	for(int i=0;i<selectedoneslist.size();i++){
		if(selectedoneslist[i] == NOOP){
			return NOOP;
		}
		else if(selectedoneslist[i] == ATTACK){
			std::vector<Player*> attackableplayercoords; 
			for(int y=0; y<selectedonevisiblecoords.size();y++){
				if(board[selectedonevisiblecoords[y]]){//gidilcek yerde player varsa ekle
					attackableplayercoords.push_back(board[selectedonevisiblecoords[y]]);
				}
			}
			if(attackableplayercoords.empty()){
				continue;
			}
			else{
				Player* lowestidplayer = attackableplayercoords[0];
				for(int x=1;x<attackableplayercoords.size();x++){
					if(attackableplayercoords[x]->getID() < lowestidplayer->getID()){
						lowestidplayer = attackableplayercoords[x];
					}
				}
				int isPlayerDead = selectedone->attackTo(lowestidplayer);
				if(isPlayerDead){
					cout << lowestidplayer->getFullName() << "(" << lowestidplayer->getHP() << ") DIED." << endl;
					for(int j = 0; j< players->size();j++){
						if((*players)[j] == lowestidplayer){
							players->erase(players->begin()+j);
							vectorsize--;
							delete lowestidplayer;
						}
					}
				}
				return ATTACK;
			}
		}

		else{//yönse durumu

			Coordinate newcoords = board.calculateCoordWithMove(selectedoneslist[i], selectedonescoords);
			Coordinate center(board.getSize()/2, board.getSize()/2);
			if((newcoords != selectedonescoords) && ( (newcoords-center) < (selectedonescoords-center) ) ) {
				selectedone->executeMove(selectedoneslist[i]);
				return selectedoneslist[i];
			}
			else{
				continue;
			}

		}
	}

	return NOOP;

}


Player* GameEngine::getWinnerPlayer() const{//yaz
	if(isFinished()){
		std::vector<Player *>* players = board.getplayers();
		if(players->empty()) {
			return NULL;
		}
		else if((players->size() == 1)){
			return (*players)[0];
		}
	}
	return NULL;
}

int GameEngine::vectorindexfinder(std::vector<Player *>* players, Player* p){
	for(int i=0; i < players->size();i++){
		if((*players)[i] == p){
			return i;
		}
	}
	return -1;
}

bool GameEngine::sortcalculator(Player* a, Player* b){
	return (a->getID() < b->getID());
}