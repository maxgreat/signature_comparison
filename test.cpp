#include <pybind11/pybind11.h>
#include <bit>
#include <nmmintrin.h>

int add(int i, int j) {
    return i + j;
}

int rec_countSetBits(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return (n & 1) + rec_countSetBits(n >> 1);
    }
}

unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

unsigned int bld_popcount(unsigned int n) {
    return __builtin_popcount(n);
}

unsigned int std_popcount(unsigned int n) {
    return std::popcount(n);
}

unsigned int signature_comparison(unsigned int s1, unsigned int s2) {
    return std::popcount(s1 ^ s2);
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
    m.def("countSetBits", &countSetBits, "Count the number of bits set");
    m.def("rec_countSetBits", &rec_countSetBits, "Recursively count the number of bits set");
    m.def("std_popcount", &std_popcount, "Use std::popcount popcount");
    m.def("bld_popcount", &bld_popcount, "Use builtin__popcount popcount");
    m.def("signature_comparison", &signature_comparison, "Compare two signatures");
}