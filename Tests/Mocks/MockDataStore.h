// You have to build your own mocks for types we need to mock because we cant do things at run time
#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../../DataStore.h"

// public is showing that you want to show publically you are inheriting from Datastore
// would be private from default
struct MockDataStore : public DataStore {
    // Returns bool, using SavePlayer, taking params const Player& payer, override
    MOCK_METHOD(bool, SavePlayer, (const Player& player), (override));

    // Without GMOCK
    // bool SavePlayer(const Player& player) override;
};