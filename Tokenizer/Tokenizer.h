#pragma once

#include <string>
#include <memory>
#include <cstdint>
#include <regex>

#include "Tokens.h"

typedef std::vector<std::unique_ptr<Token>> token_vec_t;

class Tokenizer {
public:
    explicit Tokenizer(const std::string& text)
            : _text_curr(text.begin()), _text_end(text.end()) {}

    token_vec_t Tokenize();

private:
    std::vector<TokenGenerator> _token_generators = std::vector<TokenGenerator>{
            NumberToken::get_generator(),
            KeywordToken::get_generator(),
            IdentifierToken::get_generator(),
            LParenToken::get_generator(),
            RParenToken::get_generator(),
            LBraceToken::get_generator(),
            RBraceToken::get_generator(),
            ArrowToken::get_generator(),
            StringLiteralToken::get_generator(),
            SemicolonToken::get_generator(),
    };

    std::string::const_iterator _text_curr;
    const std::string::const_iterator _text_end;

    uint64_t _line_number = 1;

    void panic(const std::stringstream& message) const;

    static bool must_skip(char c);
};
