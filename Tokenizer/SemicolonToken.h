#pragma once

#include <sstream>
#include <utility>

#include "Token.h"
#include "TokenGenerator.h"

class SemicolonToken : public Token {
public:
    std::string str() override {
        return "[';']";
    }

    static constexpr const char* regex = ";";
    static TokenGenerator get_generator() {
        return (TokenGenerator) {
                .regex = std::regex(SemicolonToken::regex),
                .generate = [](std::string matches[]) {
                    return std::make_unique<SemicolonToken>();
                }
        };
    }

    ~SemicolonToken() override = default;

private:
};