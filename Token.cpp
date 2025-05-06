#include <iostream>
#include <vector>
#include "ScannerClass.h"

int main() {
    std::string input;
    std::cout << "Enter input: ";
    std::getline(std::cin, input);

    ScannerClass scanner(input);
    std::vector<Token> tokens;

    while (true) {
        Token token = scanner.getNextToken();
        if (token.type == END_OF_INPUT) break;
        tokens.push_back(token);
    }

    for (const Token& token : tokens) {
        std::cout << "Token(Type: " << tokenTypeToString(token.type)
                  << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}