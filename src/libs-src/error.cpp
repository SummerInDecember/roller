#include "../libs/error.hh"
#include <iostream>

using namespace std;

void Error::showErrorAndExit(string err)
{
    cout << "-----ERROR-----\n";
    cout << "Error: " << err << "\n";
    cout << "Exiting...\n";
    exit(1);
}