#include "Array.h"

Array::Array(size_t n) {
    mpArray = new int(n);
}

int& Array::operator [] (size_t n)  {
    return mpArray[n];
}
