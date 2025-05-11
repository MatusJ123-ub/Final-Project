#include "ScannerClass.h"
#include <cctype>

//Token Constructor Implementation
Token::Token(TokenType typeOfToken, const std::string& valueOfToken)
: type(typeOfToken), value(valueOfToken) {}

//Scans the input string and returns the next token
Token getNextToken(const std::string& input, size_t& pos) {
    while (pos < input.length() && std::isspace(input[pos])) {
        pos++;
    }

    if (pos >= input.length()) {
        return { END_OF_INPUT, "" };
    }

    char curr = input[pos];

   //Checks for negative numbers
    if (curr == '-' && pos + 1 < input.length() && std::isdigit(input[pos + 1])) {
        std::string number;
        number += input[pos++];

        while (pos < input.length() && std::isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

  //Checks for positive numbers
    if (std::isdigit(curr)) {
        std::string number;
        while (pos < input.length() && std::isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    //Checks for arithmetic operators
    if (curr == '+' || curr == '-' || curr == '*' || curr == '/' || curr == '%'){
        pos++;
        return Token(OPERATOR, std::string(1,curr));
    }

     // Check for parentheses
     if (curr == '(' || curr == ')') {
        pos++;
        return Token(PARENTHESIS, std::string(1, curr));
    }

    //if nnone of the above match, it will be unknown character. 
    std::string unknown;
    unknown += input[pos++];
    return Token(UNKNOWN, unknown);

}
