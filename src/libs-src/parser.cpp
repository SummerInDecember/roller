#include "../libs/parser.hh"
#include "../libs/error.hh"
#include <iostream>
#include <vector>

using namespace std;

Parser::Parser(string progFile)
{
    keywords = new KeyWords;
    functions = new HashTable();

    if(progFile.find(keywords->MAIN) == string::npos)
    {
        Error::showErrorAndExit("No main function detected");
    }
    getMainFunc(progFile);
}

vector<string>Parser::getFunctions(string data)
{
    //TODO: make this do something useful
    vector<string> functions;
    int firstElement = -1;
    int idxLastCurlyBrac, idxFun;

    while(firstElement != string::npos)
    {
        if(data.find(keywords->FUNCTION, firstElement + 1) == string::npos)
            break;
        
        
    }
}

void Parser::getMainFunc(string data)
{
    size_t mainIdx, curlIdx, lastCurlIdx;
    unsigned short int amountOfCurls = 0;
    mainIdx = data.find(keywords->MAIN);
    curlIdx = data.find('{', mainIdx + 1);

    for(size_t i = curlIdx; i < data.length(); i++)
    {
        if(data[i] == '}' || data[i] == '{')
        {
            amountOfCurls++;
            lastCurlIdx = i;
            if(amountOfCurls % 2 == 0 && data[lastCurlIdx] == '}')
                break;
        }
    }
    mainFunc = data.substr(curlIdx, (lastCurlIdx + 1));
}
