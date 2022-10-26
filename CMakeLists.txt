cmake_minimum_required(VERSION 3.22)
project(Cequal__)

set(CMAKE_CXX_STANDARD 20)

string(APPEND CMAKE_C_FLAGS_DEBUG "-O0")

add_executable(Cequal__ main.cpp Tokenizer/Tokenizer.cpp Tokenizer/Tokenizer.h Tokenizer/Token.h Tokenizer/NumberToken.h Tokenizer/TokenGenerator.h Tokenizer/IdentifierToken.h Tokenizer/LParenToken.h Tokenizer/RParenToken.h Tokenizer/ArrowToken.h Tokenizer/LBraceToken.h Tokenizer/StringLiteralToken.h Tokenizer/SemicolonToken.h Tokenizer/RBraceToken.h Tokenizer/KeywordToken.h)
