#pragma once

#include <utility>
#include <list>

#include "Tokenizer.h"
#include "Nodes/Node.h"
#include "NodeGenerator.h"
#include "FunctionDefinitionNodeGenerator.h"

#define NODE_GENERATOR_AMT (sizeof(NODE_GENERATORS) / sizeof(NODE_GENERATORS[0]))

class Parser {
public:
    explicit Parser(const token_vec_t& tokens)
            : _tokens(tokens) {};

    std::unique_ptr<Node> parse();

    ~Parser() {
        for(auto & i : NODE_GENERATORS) {
            delete i;
        }
    }

private:
    const token_vec_t& _tokens;

    size_t _token_offset = 0;

    inline static NodeGenerator* const NODE_GENERATORS[] = {
            new FunctionDefinitionNodeGenerator
    };;

    std::list<NodeGenerator*> _node_generators;

    void reset_node_generators() {
        _node_generators.clear();

        for(auto & i : NODE_GENERATORS) {
            _node_generators.push_back(i);
        }
    }
};