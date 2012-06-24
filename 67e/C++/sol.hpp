#ifndef SOL_67E_HPP
#define SOL_67E_HPP

#include <cstdint>
#include <cassert>

template<unsigned int i>
uint32_t int_reverse(uint32_t t) {
    unsigned int const half = i/2;
    unsigned int const uhalf = i/2 + i%2;
    unsigned int const mask = (1 << half) - 1;
    unsigned int const umask = (1 << uhalf) - 1;
    uint32_t const top = int_reverse<half>(t & mask);
    uint32_t const bottom = int_reverse<half>(t >> uhalf);
    uint32_t const middle = t & umask & ~mask;
    return (top << uhalf) | middle | bottom;
}

template<>
uint32_t int_reverse<1>(uint32_t t) {
    return t;
}

#endif
