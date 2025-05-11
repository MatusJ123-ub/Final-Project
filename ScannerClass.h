#ifndef SCANNERCLASS_H
#define SCANNERCLASS_H


#include <string>
#include "Token.h"

//Function Delcaration that gets the next token from input string
Token getNextToken(const std::string& input, size_t& pos);

#endif