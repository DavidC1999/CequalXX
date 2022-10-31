#pragma once

class Token {
public:
    [[nodiscard]] virtual std::string str() const = 0;
    [[nodiscard]] virtual int64_t type_id() const = 0;

    virtual ~Token() = default;
};
