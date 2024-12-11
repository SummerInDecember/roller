#include <iostream>
#include "libs/parser.hh"
#include "libs/error.hh"
#include "libs/hashtable.hh"
#include <fstream>

using namespace std;
int main(int argc, char** argv)
{
    if(argc < 2)
        Error::showErrorAndExit("Not enough arguments");

    if(argv[1][0] != '-')
    {
        string data = "", line;
        ifstream prog(argv[1]);
        while(getline(prog, line))
            data += line;
        Parser parser(data);
    }
    return 0;
}

