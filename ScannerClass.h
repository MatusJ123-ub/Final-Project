#ifndef SCANNERCLASS_H
#define SCANNERCLASS_H


#include <string>
#include "Token.h"

Token getNextToken(const std::string& input, size_t& pos);

#endif