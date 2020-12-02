#pragma once
#include <memory>
#include <ostream>
// #include "DataStore.h"

/*
    @brief
    @param
    @return A class that retains a kill count
*/

struct DataStore;

class Player {
    int killCount = 0;
    std::shared_ptr<DataStore> dataStore;

public:
    //https://en.cppreference.com/w/cpp/language/explicit
    explicit Player(std::shared_ptr<DataStore> dataStore);

    // When you say a method is const it will not
    // Modify anything
    int GetKillCount() const;
    int UpdateKillCount(int delta);
    bool Save();

    friend std::ostream& operator<<(std::ostream& os, const Player& p) {
        return os << "Player { KillCount: " << p.killCount << " }";
    }
};

