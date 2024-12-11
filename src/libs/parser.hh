#pragma once

#include <iostream>
#include <vector>
#include "hashtable.hh"

using namespace std;

class Parser
{

private:
    vector<string> getFunctions(string data);
    vector<vector<string>> getVars(string data);
    HashTable* functions;
    string mainFunc;
    void getMainFunc(string data);
public:
    struct KeyWords
    {
        string FUNCTION = "func";
        string VAR = "var";
        string MAIN = "main";
    };

    KeyWords* keywords;
    Parser(string progFile);
        
};
