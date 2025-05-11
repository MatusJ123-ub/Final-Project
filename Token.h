#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

enum TokenType {
    NUMBER,
    OPERATOR,
    PARENTHESIS,
    UNKNOWN,
    END_OF_INPUT
};

struct Token {
    TokenType type;
    string value;

    Token(TokenType typeOfToken, const string& valueOfToken);
};

#endif
