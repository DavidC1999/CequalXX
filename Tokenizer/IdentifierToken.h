#pragma once

#include <cstdint>
#include <string>
#include <sstream>
#include <utility>

#include "Token.h"
#include "TokenGenerator.h"

class IdentifierToken : public Token {
public:
    explicit IdentifierToken(std::string string) : _string(std::move(string)) {}

    [[nodiscard]] const std::string& get_string() const {
        return _string;
    }

    std::string str() override {
        std::ostringstream output;
        output << "[IDENTIFIER: " << _string << "]";
        return output.str();
    }

    static constexpr const char* regex = "[a-zA-Z_][a-zA-Z0-9_]*";
    static TokenGenerator get_generator() {
        return (TokenGenerator) {
                .regex = std::regex(IdentifierToken::regex),
                .generate = [](std::string matches[]) {
                    // matches[0] is full matched string
                    return std::make_unique<IdentifierToken>(matches[0]);
                }
        };
    }

    ~IdentifierToken() override = default;

private:
    std::string _string;
};