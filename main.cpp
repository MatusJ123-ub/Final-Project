#include <iostream>
#include <vector>
#include "ScannerClass.h"
#include "Token.h"
using namespace std; 

int main() {
    //asks the user for an arithmetic expression
    std::string input;
    cout << "Enter an arithmetic expression: "; 
    getline(cin, input); 

    size_t position = 0;
    vector<Token> tokens; 

//Call getNextToken repeatedly to tokenize the entire input
    while (true) {
       Token token = getNextToken(input, position);
       if (token.type == END_OF_INPUT) {
        break;
       }
       tokens.push_back(token); 
    }
    //Print each token's type and value 
    cout << "\nTokens:\n";
    for (const Token& token : tokens) {
        cout << "Token(Type: ";
        switch (token.type) {
            case NUMBER: cout << "NUMBER"; break;
            case OPERATOR: cout << "OPERATOR"; break;
            case PARENTHESIS: cout << "PARENTHESIS"; break;
            case UNKNOWN: cout << "UNKNOWN"; break;
            default: cout << "OTHER"; break;
        }
        cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}