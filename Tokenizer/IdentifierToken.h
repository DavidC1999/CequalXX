#pragma once

#include <cstdint>
#include <string>
#include <sstream>
#include <utility>

#include "Token.h"
#include "TokenGenerator.h"

class IdentifierToken : public Token {
public:
    static inline constexpr int64_t TYPE_ID = __COUNTER__;

    explicit IdentifierToken(std::string string) : _string(std::move(string)) {}

    [[nodiscard]] const std::string& get_string() const {
        return _string;
    }

    [[nodiscard]] std::string str() const override {
        std::ostringstream output;
        output << "[IDENTIFIER: " << _string << "]";
        return output.str();
    }

    [[nodiscard]] int64_t type_id() const override {
        return TYPE_ID;
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