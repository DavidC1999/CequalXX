#include "helper_functions.h"

void print_indent(std::ostream& stream, uint64_t amt) {
    amt *= SPACES_PER_INDENT;
    while(amt-- > 0) {
        stream << ' ';
    }
}