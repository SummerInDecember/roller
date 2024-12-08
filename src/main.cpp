#include <iostream>
#include "libs/parser.hh"
#include "libs/error.hh"
#include "libs/hashtable.hh";

using namespace std;
int main(int argc, char** argv)
{
    if(argc < 2)
        Error::showErrorAndExit("Not enough arguments");

    if(argv[1][0] != '-')
    {
        
    }
    return 0;
}

