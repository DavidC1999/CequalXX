#pragma once

#include <Token.h>
#include <memory>

#include "Nodes/Node.h"

class NodeGenerator {
public:
    NodeGenerator() noexcept = default;

    virtual ~NodeGenerator() = default;

    virtual bool feed_token(const Token* const token) = 0;
    virtual std::unique_ptr<Node> create() = 0;
};