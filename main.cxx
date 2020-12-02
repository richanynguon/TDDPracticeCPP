#include <iostream>
#include <string>
#include <memory>

#include "Player.h"
#include "DataStore.h"

// param - this is how you get your arguements, argc # if args and argv is the params itself
int main(int argc, char **argv) {
    // auto means the compiler can figure it out
    Player player(std::make_shared<DataStore>());
    player.UpdateKillCount(12);
    std::cout << "We have a player: " << player << std::endl;
}