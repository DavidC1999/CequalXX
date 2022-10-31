#pragma once

struct Node {
    [[nodiscard]] virtual std::string str(uint64_t indent = 0) const = 0;

    virtual ~Node() = default;
};