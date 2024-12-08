#include <gtest/gtest.h>
#include "../src/libs/hashtable.hh"
#include <iostream>

using namespace std;

class HashTableTest : public ::testing::Test {
protected:
    void SetUp() override {
        table = new HashTable();
    }
    void TearDown() override {
        delete table;
    }
    HashTable *table;
};

TEST_F(HashTableTest, AddTest) {
    bool res = table->add("1", "ew", NULL);
    EXPECT_TRUE(res);
}

TEST_F(HashTableTest, GetTest) {
    table->add(to_string(0), to_string(0), NULL);
    string firstGet = table->getValue("0");

    for(int i = 1; i<250; i++) // testing if i can still access the value after resizing
    {
        table->add(to_string(i), to_string(i), NULL);
    }

    string secondGet = table->getValue("0");
    
    EXPECT_TRUE(firstGet == secondGet);
}

TEST_F(HashTableTest, RemoveTest) {
    table->add("1", "ew", NULL);
    string before = table->getValue("1");
    table->remove("1");
    string after = table->getValue("1");
    EXPECT_TRUE(after == ERROR_KEY_NOT_FOUND && before != after);
}


