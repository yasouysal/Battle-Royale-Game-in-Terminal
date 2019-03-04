#include "GameParser.h"
#include "Berserk.h"
#include "Pacifist.h"
#include "Ambusher.h"
#include "Tracer.h"
#include "Dummy.h"
#include "Player.h"
#include <string.h>
#include <utility>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/


std::pair<int, std::vector<Player *> *> GameParser::parseFileWithName(const std::string& filename){
	//cout << "girdim" << endl;
	//std::pair<int, std::vector<Player *> *> recordedpair;
	std::vector<Player*>* playervector = new std::vector<Player*> {};
	ifstream file;
	file.open(filename.c_str());
	//char* p;
	//const char tokenparameter[3] = "::";
	//std::string::size_type sz;
	string str1;
    string str2;
    string str3;
    string str4;
    string fullplayerline;
    string playerid;
    string playertype;
    string playerxcoord;
    string playerycoord;
    std::getline(file,str1,':');//Board size yazisi
    std::getline(file,str2);//Board size degeri
    std::getline(file,str3,':');//Player count yazisi
    std::getline(file,str4);//Player count degeri
    int boardSize = stoi(str2);
    //while(file.good()){
    for(int i = 0; i < stoi(str4); i++){
    	/*
    	getline(file,fullplayerline);
    	p = strtok (fullplayerline,tokenparameter);
    	playerid = p;
    	p = strtok (NULL,tokenparameter);
    	playertype = p;
    	p = strtok (NULL,tokenparameter);
    	playerxcoord = p;
    	p = strtok (NULL,tokenparameter);
    	playerycoord = p;
    	*/
    	
    	getline(file,playerid,':');
    	getline(file,fullplayerline,':');
    	getline(file,playertype,':');
    	getline(file,fullplayerline,':');
    	getline(file,playerxcoord,':');
    	getline(file,fullplayerline,':');
    	getline(file,playerycoord);

    	//cout << "bi tur yaptim" << endl;
		

    	if(playertype == "Tracer"){
    		Player* newplayer = new Tracer(stoi(playerid),stoi(playerxcoord),stoi(playerycoord));
   		    //cout << "traceri olusturdum" << endl;
    		playervector->push_back(newplayer);
   		    //cout << "pushladim" << endl;

    	}
    	else if(playertype == "Ambusher"){
    		Player* newplayer = new Ambusher(stoi(playerid),stoi(playerxcoord),stoi(playerycoord));
    		//recordedpair.second -> push_back(newplayer);
    		playervector->push_back(newplayer);
    	}
    	else if(playertype == "Dummy"){
    		Player* newplayer = new Dummy(stoi(playerid),stoi(playerxcoord),stoi(playerycoord));
    		//recordedpair.second -> push_back(newplayer);
    		playervector->push_back(newplayer);
    	}
    	else if(playertype == "Berserk"){
    		Player* newplayer = new Berserk(stoi(playerid),stoi(playerxcoord),stoi(playerycoord));
    		//recordedpair.second -> push_back(newplayer);
    		playervector->push_back(newplayer);
    	}
    	else if(playertype == "Pacifist"){
    		Player* newplayer = new Pacifist(stoi(playerid),stoi(playerxcoord),stoi(playerycoord));
    		//recordedpair.second -> push_back(newplayer);
    		playervector->push_back(newplayer);
    	}

		//cout << "atadim" << endl;


    }

    file.close();
    std::pair<int, std::vector<Player *> *> recordedpair(boardSize,playervector);
    
    /*
    vector<Player*>::iterator xd;
    for(xd = playervector.begin(); xd != playervector.end(); xd++){
        std::cout<< (*xd)->getID()<<std::endl;
        std::cout<< (*xd)->getHP()<<std::endl;
        std::cout<< (*xd)->getCoord()<<std::endl;
    }
    */
    

    return recordedpair;

}