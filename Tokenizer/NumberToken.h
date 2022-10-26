#pragma once

#include <cstdint>
#include <string>
#include <sstream>

#include "Token.h"
#include "TokenGenerator.h"

class NumberToken : public Token {
public:
    explicit NumberToken(int64_t number) : _number(number) {}

    [[nodiscard]] int64_t get_number() const {
        return _number;
    }

    std::string str() override {
        std::ostringstream output;
        output << "[NUMBER: " << _number << "]";
        return output.str();
    }

    static constexpr const char* regex = "[0-9]+";
    static TokenGenerator get_generator() {
        return (TokenGenerator) {
                .regex = std::regex(NumberToken::regex),
                .generate = [](std::string matches[]) {
                    // matches[0] is full matched string
                    return std::make_unique<NumberToken>(std::stoi(matches[0]));
                }
        };
    }

    ~NumberToken() override = default;

private:
    int64_t _number;
};