#pragma once

/**
 * Okay, I know this looks reaaaallly weird 
 * but it has a good reason to be like this.
 * I needed something to represent a key not found
 * but I needed it to be something I knew it was very 
 * unlikely to get used so I decided to do
 * this crime against humanity
 * 
 * Sorry
 */
#define ERROR_KEY_NOT_FOUND "tt\nKEY\tNOT\\//Found ««KEYnotFOUNd\n»»»"

#include <iostream>

using namespace std;

typedef struct node
{
    std::string key;
    std::string value;

    struct node* next;
};

class HashTable
{

private:
    void setNode(node* nd, string key, string value);
    int nodesCount, usedCount, capacity;
    struct node** table;
    bool resize();
public:
    HashTable();
    int hashFunction(std::string key);
    bool add(std::string key, std::string value, node** arr);

    std::string getValue(std::string key);
    void remove(std::string key);
    int getNodesCount();

    int getUsedCount();
    int getCapacity();
};