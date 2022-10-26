#pragma once

#include <regex>

#include "Token.h"

struct TokenGenerator {
    std::regex regex;
    std::function<std::unique_ptr<Token>(std::string[])> generate;
};