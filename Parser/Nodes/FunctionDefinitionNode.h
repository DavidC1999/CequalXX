#pragma once

#include <string>
#include <sstream>
#include <cstdint>

#include "Node.h"

#include "../../helper_functions.h"

struct FunctionDefinitionNode : public Node {
    std::string name;

    [[nodiscard]] std::string str(uint64_t indent) const override {
        std::stringstream output;
        print_indent(output, indent);
        output << "Function definition {" << std::endl;
        print_indent(output, indent + 1);
        output << "Name: " << name << std::endl;
        print_indent(output, indent);
        output << "}" << std::endl;

        return output.str();
    }
};
