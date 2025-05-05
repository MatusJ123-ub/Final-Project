#ifndef SCANNERCLASS_H
#define SCANNERCLASS_H

#include <string>

#pragma once

enum TokenType {
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LPAREN,
    RPAREN,
    UNKNOWN,
    END_OF_INPUT
};

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType typeOfToken, const string& valueOfToken)
    : type(typeOfToken), value(valueOfToken) {}

};

class ScannerClass
{
public:
    ScannerClass(const string& input);
   Token getNextToken();

private:
string input;
size_t pos;

};

std::string tokenTypeToString(TokenType type);

#endif