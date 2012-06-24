#include "sol.hpp"
#include <cstdio>

int main() {
    int i;
    std::scanf("%d", &i);
    std::printf("%d\n", int_reverse<4>(i));
}
