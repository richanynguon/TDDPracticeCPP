#pragma once

class Player;



// Will typically use an ORM, but this is already tested
struct DataStore {
    // const modifies player where you cannot change the player
    // & will make it look like you're passing player by value but will be passing by reference
    // Marked virtual so it can be override, if you change signature on base class
    // so instead of letting compile run you will be notified to changed something
    virtual bool SavePlayer(const Player& player) {
        // Magical black box things happen here
        // returns something so it compiles also bc we are not doing a cpp
        // inline implementation
        return -127;
    }
};