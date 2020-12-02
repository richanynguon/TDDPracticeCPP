#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Player.h"
#include "Mocks/MockDataStore.h"

// Google Test Fixture

// Struct vs Class
// Struct will default public
// Class is default private
struct PlayerTest : testing::Test {
    // Unique Ptrs can only be passed by reference or by rvalue reference so you don't have to clean up memory
    // Doesn't require user to allocate and deallocate mem in heap
    std::unique_ptr<Player> player;
    // For Mocking
    // you can give a default to a member variable its like when unqiue ptr Player with constructor PlayerTest
    std::shared_ptr<MockDataStore> mockDataStore = std::make_shared<MockDataStore>();

    // Constructor
    PlayerTest() {
        // Similar to new Player();
        player = std::make_unique<Player>(mockDataStore);
    }

    // Breakdown
    virtual ~PlayerTest() {

    }
};

// Test_F taking two params, the test fixture, and the test name
// If assert fails test is done, if expect fail it will keep going
TEST_F(PlayerTest, GetKillCountShouldReturnZeroWhenPlayerIsCreated) {
    EXPECT_EQ(0, player->GetKillCount());
}

// Test will only need to care about outward results
TEST_F(PlayerTest, UpdateKillCountShouldUpdateKillCountAndReturnIt){
    EXPECT_EQ(2, player->UpdateKillCount(2));
    EXPECT_EQ(2, player->GetKillCount());
}

TEST_F(PlayerTest, UpdateKillCountShouldNotGoBelowZero) {
    EXPECT_EQ(0, player->UpdateKillCount(-1));
    EXPECT_EQ(0, player->GetKillCount());
}

// How to Mock a result from external systems in a unit test so it stays true to TDD
TEST_F(PlayerTest, SaveShouldReturnWhetherOrNotTheBackingStoreSucceeds) {
    // test should not care about implementation detail
    // "too focused on implementation"
    // another way to solve this you can put these into fixture
    // but it just moves the problem around eg: player test working data store
    // player test non working data store
                                            // Ref makes it so it doesnt make a copy
                                            // make it do it with this player that was just created
    // EXPECT_CALL(*mockDataStore, SavePlayer(testing::Ref(*player)))
    // without it we are saying we dont care which player object
    ON_CALL(*mockDataStore, SavePlayer)
        .WillByDefault(testing::Return(true));
    EXPECT_TRUE(player->Save());

    ON_CALL(*mockDataStore, SavePlayer)
        .WillByDefault(testing::Return(false));
    EXPECT_FALSE(player->Save());
}

TEST_F(PlayerTest, SaveShouldSaveCorrectPlayerData){
    EXPECT_CALL(*mockDataStore, SavePlayer(testing::Ref(*player)))
        .Times(testing::Exactly(1));
    player->Save();
}