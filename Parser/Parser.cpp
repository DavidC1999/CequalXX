#include "Parser.h"

std::unique_ptr<Node> Parser::parse() {
    reset_node_generators();

    std::unique_ptr<Node> output;

    while(_token_offset < _tokens.size()) {
        auto it = _node_generators.begin();
        while (it != _node_generators.end()) { // loop through all possible node generators left
            NodeGenerator* generator = *it;


            bool fits = generator->feed_token(_tokens[_token_offset].get());
            if (!fits) {
                if (_node_generators.size() == 1) {
                    // last token, this is the chosen one
                    output = (*it)->create();
                    // TODO: check for error in create function
                }

                _node_generators.erase(it++);
            } else {
                ++it;
            }
        }
        ++_token_offset;
    }
    return output;
}
