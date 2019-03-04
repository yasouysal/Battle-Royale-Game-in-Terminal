#include "TestableGameParser.h"
using namespace std;
#include "GameParser.h"

void TestableGameParser::runInternal() {
    // Phase 1: Parse the given file.

    /**
     * Board Size: 3
     * Player Count: 2
     * 0::Tracer::2::0
     * 1::Berserk::2::2
     */

    /**
     * It should boil down to:
     *
     * Tracer(0, 2, 0)
     * Berserk(1, 2, 2)
     */

    //cout << "testabledayim" << endl;

    auto parsedValues = GameParser::parseFileWithName(this->filenameToTest);

    //cout << "parseettim" << endl;

    if(parsedValues.first != 3)
        currentGrade -= 2;

    std::vector<Player *> *players = parsedValues.second;

    if(players->size() != 2)
        currentGrade -= 2;

    //cout << "removea geldim" << endl;
    //cout << "currentGrade: " << currentGrade << endl;

    /*
    for(int i = 0; i < players->size(); i++){
        cout << (players*)[i]->getID() << endl;
        cout << (players*)[i]->getHP() << endl;
        cout << (players*)[i]->getCoord() << endl;
    }
    */
    
    /*
    std::vector<Player *>::iterator xd;
    for(xd = players->begin(); xd != players->end(); xd++){
        std::cout<< (*xd)->getID() << std::endl; 
        std::cout<< (*xd)->getHP() << std::endl; 
        //std::cout<< "hp yazdirdim" << std::endl;
        std::cout<< (*xd)->getWeapon() << std::endl; 
    }
    std::cout<<"adsasdas"<<std::endl;
    */

    // Removing memory manually...
    // Normally GameEngine will/should do this.

    for(Player *player : *players) {
        //cout << player ->getID() << endl;
        //cout << player ->getCoord() << endl;
        //cout << player ->getHP() << endl;
        delete player;
        //cout << "bi tane sildim" << endl;

    }

    players->clear();
    delete players;
}
