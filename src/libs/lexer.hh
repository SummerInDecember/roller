#pragma once

#include <iostream>

using namespace std;

namespace Lexer{

    enum Types{
        ILLEGAL,
        EOFILE,
        IDENTIFIER,
        SEMICOLON,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        ASSIGN,
        INT,
        EQUAL
    };

    class Token{

        private:
        
        public:
        Types _type;
        string _literal;
        Token(Types type, string literal);
    };
    class Lexer{
        private:
        char seeNextChar();
        int charIdx, charNextIdx;
        char currentChar;
        string getNumber();
        void moveChar();
        void skipWhitespace();
        public:
        string input;
        Lexer(string inpt);

        Token* getNextToken();

    };
}