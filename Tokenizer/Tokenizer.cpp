#include <iostream>
#include "Tokenizer.h"

token_vec_t Tokenizer::Tokenize() {
    token_vec_t output;
    while(_text_curr != _text_end) {
        if(*_text_curr == '\n') {
            ++_line_number;
        }

        if(must_skip(*_text_curr)) {
            ++_text_curr;
            continue;
        }

        bool found_match = false;
        for (auto& generator: _token_generators) {
            std::regex_iterator<std::string::const_iterator> iter(_text_curr, _text_end, generator.regex);
            std::regex_iterator<std::string::const_iterator> end;

            // check if we have any match at all
            if (iter == end) {
                continue;
            }

            std::match_results results = *iter;

            // check if the match is at the start of the text
            if (results.position() != 0) {
                continue;
            }

            // move the text along
            _text_curr += results.length();

            std::string matches[results.size()];

            int count = 0;
            for (const auto& result: results) {
                matches[count++] = result.str();
            }

            std::unique_ptr<Token> token = generator.generate(matches);

            output.push_back(std::move(token));

            found_match = true;
            break;
        }

        if(!found_match) {
            std::stringstream message;
            message << "unexpected character: " << *_text_curr;
            panic(message);
        }
    }
    return output;
}

bool Tokenizer::must_skip(char c) {
    return c == '\n' || c == '\r' || c == '\t' || c == ' ';
}

void Tokenizer::panic(const std::stringstream& message) const {
    std::cerr << "Error in tokenizing on line " << _line_number << ": " << message.str();
    exit(1);
}
