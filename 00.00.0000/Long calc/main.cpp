#include "LongCalc.cpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    long n = 0;
    std::cin >> n;
    LongNumber mN;
    mN = n;
    mN.PrintNumber();

    return 0;
}
