#include "../libs/lexer.hh"
#include "../libs/error.hh"
#include <iostream>

using namespace std;

namespace Lexer{
    Lexer::Lexer(string inpt)        
    {
        if(inpt.empty())
            currentChar = NULL;
        else
        {
            input = inpt;
            currentChar = input[0];
        }

        charIdx = 0;
        charNextIdx = 1;
       
    }

    Token* Lexer::getNextToken()
    {
        skipWhitespace();

        Token* tken = NULL;
        string strChar(1, currentChar);

        if(currentChar == ';')
            tken = new Token(SEMICOLON, ";");
        else if(currentChar == '+')
            tken = new Token(PLUS, "+");
        else if(currentChar == '-')
            tken = new Token(MINUS, "-");
        else if(currentChar == '/')
            tken = new Token(DIVIDE, "/");
        else if(currentChar == '*')
            tken = new Token(MULTIPLY, "*");
        else if(currentChar == '=')
        {
            if(seeNextChar() == '=')
            {
                moveChar();
                tken = new Token(EQUAL, "==");
            }
            else
                tken = new Token(ASSIGN, "=");
        }
        else if(isdigit(currentChar))
            tken = new Token(INT, getNumber());
        else
            tken = new Token(ILLEGAL,strChar);
        
        moveChar();
        return tken; 
    }

    void Lexer::skipWhitespace()
    {
        while(currentChar != NULL && (currentChar == ' ' || currentChar == '\t' 
        || currentChar == '\n' || currentChar == '\r'))
        {
            moveChar();
        }
    }
    void Lexer::moveChar()
    {
        if(charNextIdx >= input.length())
            currentChar = NULL;
        else
            currentChar = input[charNextIdx];

        charIdx = charNextIdx;
        charNextIdx++;
    }

    string Lexer::getNumber()
    {
        string num;

        while(isdigit(currentChar))
        {
            num += currentChar;
            if(isdigit(input[charNextIdx]))
                moveChar();
            else 
                break;
        }

        return num;
    }

    char Lexer::seeNextChar()
    {
        if(charNextIdx >= input.length())
            return NULL;
        return input[charNextIdx];
    }

}

namespace Lexer
{

    Token::Token(Types type, string literal)
    {
        _type = type;
        _literal = literal;  
    }
}