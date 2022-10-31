#pragma once

#include <sstream>
#include <cstdint>

#define SPACES_PER_INDENT 4

void print_indent(std::ostream& stream, uint64_t amt);