#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

// TokenType defines what kind of token will be read from the input 
enum TokenType {
    NUMBER,   //Numeric Value
    OPERATOR, //+,-,*,/
    PARENTHESIS,// open and close parenthesis
    UNKNOWN,  //Anything that doesn't fit in the other categories
    END_OF_INPUT //Token that indicates we are done scanning
};

//Token hold both type and the value of the token
struct Token {
    TokenType type;
    string value;

    //Constructor 
    Token(TokenType typeOfToken, const string& valueOfToken);
};

#endif
