#include "ScannerClass.h"
#include <cctype>

Token::Token(TokenType typeOfToken, const std::string& valueOfToken)
: type(typeOfToken), value(valueOfToken) {}

Token getNextToken(const std::string& input, size_t& pos) {
    while (pos < input.length() && std::isspace(input[pos])) {
        pos++;
    }

    if (pos >= input.length()) {
        return { END_OF_INPUT, "" };
    }

    char curr = input[pos];

   
    if (curr == '-' && pos + 1 < input.length() && std::isdigit(input[pos + 1])) {
        std::string number;
        number += input[pos++];
        while (pos < input.length() && std::isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

  
    if (std::isdigit(curr)) {
        std::string number;
        while (pos < input.length() && std::isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    switch (curr) {
        case '+': pos++; return Token(PLUS, "+");
        case '-': pos++; return Token(MINUS, "-");
        case '*': pos++; return Token(MULTIPLY, "*");
        case '/': pos++; return Token(DIVIDE, "/");
        case '(': pos++; return Token(LPAREN, "(");
        case ')': pos++; return Token(RPAREN, ")");
        default:
            std::string unknown;
            unknown += input[pos++];
            return Token(UNKNOWN, unknown);
    }
}

std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case NUMBER: return "NUMBER";
        case PLUS: return "PLUS";
        case MINUS: return "MINUS";
        case MULTIPLY: return "MULTIPLY";
        case DIVIDE: return "DIVIDE";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case UNKNOWN: return "UNKNOWN";
        default: return "END_OF_INPUT";
    }
}