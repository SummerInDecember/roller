#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Parser
{

private:
    vector<string> parseByBlocks(string fileData);
public:
    Parser(string progFile);
    ~Parser();
        
};
