cmake_minimum_required(VERSION 3.22)
project(Cequal__)

set(CMAKE_CXX_STANDARD 20)

include_directories(Tokenizer)

add_executable(Cequal__ main.cpp Tokenizer/Tokenizer.cpp Tokenizer/Tokenizer.h Tokenizer/Token.h Tokenizer/NumberToken.h Tokenizer/TokenGenerator.h Tokenizer/IdentifierToken.h Tokenizer/LParenToken.h Tokenizer/RParenToken.h Tokenizer/ArrowToken.h Tokenizer/LBraceToken.h Tokenizer/StringLiteralToken.h Tokenizer/SemicolonToken.h Tokenizer/RBraceToken.h Tokenizer/KeywordToken.h Parser/Parser.cpp Parser/Parser.h Parser/Nodes/FunctionDefinitionNode.h Parser/FunctionDefinitionNodeGenerator.cpp Parser/FunctionDefinitionNodeGenerator.h Tokenizer/Tokens.h Parser/NodeGenerator.h Parser/Nodes/Node.h helper_functions.h helper_functions.cpp)
