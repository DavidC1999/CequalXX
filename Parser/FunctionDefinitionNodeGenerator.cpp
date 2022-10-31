#include "FunctionDefinitionNodeGenerator.h"

bool FunctionDefinitionNodeGenerator::feed_token(const Token* const token) {
    switch(_state) {
        case STATE_KEYWORD_FUNC: {
            if (token->type_id() != KeywordToken::TYPE_ID) return false;
            const auto* keyword_token = (const KeywordToken*) token;
            if (keyword_token->get_string() != "func") return false;

            _ret_val = std::make_unique<FunctionDefinitionNode>();

            _state = STATE_IDENTIFIER;
            return true;
        }
        case STATE_IDENTIFIER: {
            if (token->type_id() != IdentifierToken::TYPE_ID) return false;
            const auto* identifier_token = (const IdentifierToken*)token;
            _ret_val->name = identifier_token->get_string();
            _state = STATE_ARROW;
            return true;
        }
        case STATE_ARROW: {
            if (token->type_id() != ArrowToken::TYPE_ID) return false;
            _state = STATE_TYPE;
            return true;
        }
        case STATE_TYPE:
            if (token->type_id() != KeywordToken::TYPE_ID) return false;
            // TODO: store type
            _state = STATE_LBRACE;
            return true;
        case STATE_LBRACE:
            if (token->type_id() != LBraceToken::TYPE_ID) return false;
            _state = STATE_RBRACE;
            return true;
        case STATE_RBRACE:
            if (token->type_id() != RBraceToken::TYPE_ID) return false;
            _state = STATE_END;
            return true;
        case STATE_END:
            return false;
    }
    return false;
}

std::unique_ptr<Node> FunctionDefinitionNodeGenerator::create() {
    // reset state so generator may be used again
    _state = STATE_KEYWORD_FUNC;
    return std::move(_ret_val);
}