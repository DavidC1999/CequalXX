#pragma once

#include <Tokenizer.h>

#include "Nodes/FunctionDefinitionNode.h"
#include "NodeGenerator.h"

class FunctionDefinitionNodeGenerator : public NodeGenerator {
public:
    FunctionDefinitionNodeGenerator() noexcept = default;

    bool feed_token(const Token* token) override;

    std::unique_ptr<Node> create() override;

private:
    enum ParseState {
        STATE_KEYWORD_FUNC = 0,
        STATE_IDENTIFIER,
        STATE_ARROW,
        STATE_TYPE,
        STATE_LBRACE,
        STATE_RBRACE,
        STATE_END,
    };

    std::unique_ptr<FunctionDefinitionNode> _ret_val;

    ParseState _state = STATE_KEYWORD_FUNC;
};