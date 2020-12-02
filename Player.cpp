#include <algorithm>
#include "Player.h"
#include "DataStore.h"

// Because this is a constructor function it can be initalize
// : dataStore { ds }  inside of {} is an intializing list
// same as func(std::shared_ptr<DataStore> ds){dataStore=ds}
Player::Player(std::shared_ptr<DataStore> ds)
    : dataStore { ds }
{ }

int Player::GetKillCount()  const
{
    return killCount;
};

int Player::UpdateKillCount(int delta) {
    // return killCount = std::max(0, killCount + delta);
    if (killCount + delta < 0)
        killCount=0;
    else
        killCount+=delta;

    return killCount;
}

bool Player::Save(){
    // Player was intialized with dataStore which is connected
    // to our struct in DataStore.h where we have a virtual method
    // this is referencing the current player,
    return dataStore->SavePlayer(*this);
}