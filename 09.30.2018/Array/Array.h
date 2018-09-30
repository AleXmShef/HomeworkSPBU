#include <iostream>

class Array{

public:
    Array(size_t n);
    int& operator [] (size_t n);

protected:
    int* mpArray = nullptr;

};
