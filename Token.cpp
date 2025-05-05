#include <cctype>
#include <iostream>
#include <vector>
using namespace std;


enum TokenType {
    NUMBER,
    UNKNOWN,
    END_OF_INPUT
};

struct Token {
    TokenType type;
    string value;

    Token(TokenType typeOfToken, const string& valueOfToken)
        : type(typeOfToken), value(valueOfToken) {}
};

Token getNextToken(const string& input, size_t& pos);

int main() {
    string input;
    cout << "Enter input: ";
    getline(cin, input);

    size_t position = 0;
    vector<Token> tokens;

    while (true) {
        Token token = getNextToken(input, position);
        if (token.type == END_OF_INPUT) {
            break;
        }
        tokens.push_back(token);
    }

    for (size_t i = 0; i < tokens.size(); i++) {
        const Token& token = tokens[i];
        cout << "Token(Type: ";
        switch (token.type) {
            case NUMBER:
                cout << "NUMBER";
                break;
            case UNKNOWN:
                cout << "UNKNOWN";
                break;
            default:
                cout << "OTHER";
        }
        cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}

Token getNextToken(const string& input, size_t& pos) {
    while (pos < input.length() && isspace(input[pos])) {
        pos++;
    }

    if (pos >= input.length()) {
        return { END_OF_INPUT, "" };
    }

    char curr = input[pos];

    // Handle negative numbers
    if (curr == '-' && pos + 1 < input.length() && isdigit(input[pos + 1])) {
        string number;
        number += input[pos++]; // Add '-' and move forward

        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    // Handle positive numbers
    if (isdigit(input[pos])) {
        string number;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    // Handle unknown tokens
    string unknown;
    while (pos < input.length() && !isspace(input[pos])) {
        unknown += input[pos++];
    }
    return Token(UNKNOWN, unknown);
}