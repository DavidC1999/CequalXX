#pragma once

class Token {
public:
    virtual std::string str() = 0;

    virtual ~Token() = default;
};
