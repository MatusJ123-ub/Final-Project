#ifndef SCANNERCLASS_H
#define SCANNERCLASS_H

#include <string>
#include <vector>


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

    Token(TokenType typeOfToken, const std::string& valueOfToken)
    : type(typeOfToken), value(valueOfToken) {}

};

class Scanner
{
public:
    Scanner(const std::string& input);
   Token getNextToken();
  

private:
std::string input;
size_t pos;

};

std::string tokenTypeString(TokenType type);

#endif