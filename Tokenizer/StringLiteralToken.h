#pragma once

#include <cstdint>
#include <string>
#include <sstream>
#include <utility>

#include "Token.h"
#include "TokenGenerator.h"

class StringLiteralToken : public Token {
public:
    explicit StringLiteralToken(std::string string) : _string(std::move(string)) {}

    [[nodiscard]] const std::string& get_string() const {
        return _string;
    }

    std::string str() override {
        std::ostringstream output;
        output << "[STRING_LITERAL: \"" << _string << "\"]";
        return output.str();
    }

    // https://regex101.com/r/hf9W0S/1
    static constexpr const char* regex = "\"((?:(?!\"|\\\\).|\\\\.)*)\"";
    static TokenGenerator get_generator() {
        return (TokenGenerator) {
                .regex = std::regex(StringLiteralToken::regex),
                .generate = [](std::string matches[]) {
                    return std::make_unique<StringLiteralToken>(matches[1]);
                }
        };
    }

    ~StringLiteralToken() override = default;

private:
    std::string _string;
};