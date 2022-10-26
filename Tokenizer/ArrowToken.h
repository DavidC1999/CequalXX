#pragma once

#include <sstream>
#include <utility>

#include "Token.h"
#include "TokenGenerator.h"

class ArrowToken : public Token {
public:
    std::string str() override {
        return "[->]";
    }

    static constexpr const char* regex = "->";
    static TokenGenerator get_generator() {
        return (TokenGenerator) {
                .regex = std::regex(ArrowToken::regex),
                .generate = [](std::string matches[]) {
                    return std::make_unique<ArrowToken>();
                }
        };
    }

    ~ArrowToken() override = default;

private:
};