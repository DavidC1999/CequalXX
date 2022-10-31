#pragma once

#include <sstream>
#include <utility>

#include "Token.h"
#include "TokenGenerator.h"

class ArrowToken : public Token {
public:
    static inline constexpr int64_t TYPE_ID = __COUNTER__;

    [[nodiscard]] std::string str() const override {
        return "[->]";
    }

    [[nodiscard]] int64_t type_id() const override {
        return TYPE_ID;
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