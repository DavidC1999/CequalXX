#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <string_view>
#include "Tokenizer/Tokenizer.h"


std::string read_file(const std::string& path) {
    std::ifstream t(path);
    if(!t.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return {};
    }

    std::stringstream buffer;
    buffer << t.rdbuf();

    return buffer.str();
}

int main() {
    std::string contents = read_file("../program.ceqpp");

    Tokenizer tokenizer(contents);

    token_vec_t tokens = tokenizer.Tokenize();

    for(auto& tok : tokens) {
        std::cout << tok->str() << std::endl;
    }
//    std::cout << contents << std::endl;



    return 0;
}
