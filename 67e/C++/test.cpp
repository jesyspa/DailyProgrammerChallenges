#include "sol.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#define BOOST_TEST_MODULE SOL67E
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(zero) {
    BOOST_CHECK_EQUAL(int_reverse<32>(0), 0);
}

BOOST_AUTO_TEST_CASE(one) {
    BOOST_CHECK_EQUAL(int_reverse<32>(1), (unsigned int)(1 << 31));
}

BOOST_AUTO_TEST_CASE(random_values) {
    boost::random::mt19937 gen;
    boost::random::uniform_int_distribution<> dist(0, INT_MAX);
    int const times = 1000;
    for (int i = 0; i < times; ++i) {
        int const j = dist(gen);
        BOOST_CHECK_EQUAL(int_reverse<32>(int_reverse<32>(j)), j);
    }
}
