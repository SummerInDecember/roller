#include <iostream>
#include "../libs/hashtable.hh"

using namespace std;

HashTable::HashTable()
{
    capacity = 100;
    table = (node**)malloc(100 * sizeof(node));

    for(int i = 0; i<capacity; i++)
        table[i] = NULL;
    
    nodesCount = 0;
    usedCount = 0;
}
int HashTable::getCapacity()
{
    return capacity;
}

int HashTable::getNodesCount()
{
    return nodesCount;
}

int HashTable::getUsedCount()
{
    return usedCount;
}

int HashTable::hashFunction(string key)
{
    int hash = 0;
    const int prime = 37;
    for(char c : key)
        hash = hash * prime + c;

    return hash % capacity;
}

/**
 * !For any use besides resize this function should only be called 
 * !in this manner: add([key], [val], NULL)
 */
bool HashTable::add( string key, string value, node** arr)
{
    if(arr == NULL)
        arr = table;
    try
    {
        if(usedCount == capacity)
            resize();
        node* newNode = new node;
        setNode(newNode, key, value);
        int idx = hashFunction(key);

        if(arr[idx] == NULL)
        {
            arr[idx] = newNode;
            usedCount++;
            nodesCount++;
            return true;
        }
        else
        {
            newNode->next = arr[idx];
            arr[idx] = newNode;
            nodesCount++;
            return true;
        }
    }
    catch(exception e)
    {
        return false;
    }
}

bool HashTable::resize()
{
    try
    {
        capacity = capacity * 2;
        node** copy = (node**)malloc(capacity * sizeof(node));

        for(int i = 0; i<capacity; i++)
            copy[i] = NULL;

        node* tmp = NULL;
        for(int i = 0; i<capacity / 2; i++)
        {
            tmp = table[i];
            while(tmp != NULL)
            {
                add(tmp->key, tmp->value, copy);
                tmp = tmp->next;
            }
        }
        
        free(table);
        table = copy;
        return true;
    }
    catch(exception e)
    {
        return false;
    }
}

string HashTable::getValue(string key)
{
    string val = ERROR_KEY_NOT_FOUND;
    int idx = hashFunction(key);
    node* current = table[idx];

    while(current!= NULL)
    {
        if(current->key == key)
        {
            val = current->value;
            break;
        }
        current = current->next;
    }

    return val; 
}

void HashTable::remove(string key)
{
    int idx = hashFunction(key);

    if(table[idx]==NULL)
        return;
    node* prev = NULL;
    node* current = table[idx];
    while (current != NULL)
    {
        if(current->key == key)
        {
            if(current == table[idx])
                table[idx] = current->next;
            else
            {           
                prev->next = current->next;
            }
            free(current);
            
            return;
        }
        prev = current;
        current = current->next;
    }
    
}

void HashTable::setNode(node* nd, string key_param, string value_param)
{
    if(nd == nullptr)
        exit(1);
    nd->key = key_param;
    nd->value = value_param;
    nd->next = NULL;
}