#pragma once

#include <cstdint>
#include <string>
#include <sstream>
#include <utility>

#include "Token.h"
#include "TokenGenerator.h"

class KeywordToken : public Token {
public:
    static inline constexpr int64_t TYPE_ID = __COUNTER__;

    explicit KeywordToken(std::string string) : _string(std::move(string)) {}

    [[nodiscard]] const std::string& get_string() const {
        return _string;
    }

    [[nodiscard]] std::string str() const override {
        std::ostringstream output;
        output << "[KEYWORD: " << _string << "]";
        return output.str();
    }

    [[nodiscard]] int64_t type_id() const override {
        return TYPE_ID;
    }

    static TokenGenerator get_generator() {
        return (TokenGenerator) {
                .regex = std::regex(get_regex()),
                .generate = [](std::string matches[]) {
                    // matches[0] is full matched string
                    return std::make_unique<KeywordToken>(matches[0]);
                }
        };
    }

    ~KeywordToken() override = default;

private:
    static constexpr const char* _keywords[] = {
            "func",
            "void",
            "var",
    };

    static std::string get_regex() {
        std::stringstream output;

        size_t keyword_amount = sizeof(_keywords) / sizeof(_keywords[0]);

        output << "(";
        for(int i = 0; i < keyword_amount - 1; ++i) {
            output << _keywords[i] << "|";
        }
        output << _keywords[keyword_amount - 1];
        output << ")";

        return output.str();
    }

    std::string _string;
};