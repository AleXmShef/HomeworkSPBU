#include <iostream>
#include <cstdlib>

int** GetppElementByOffset(int** p, int n) {
    p = p + n;
    return p;
}

int* GetpElementByOffset(int* p, int n) {
    p = p + n;
    return p;
}

int Comparator(const void* el1, const void* el2)
{
    return (*reinterpret_cast<const int*>(el1) - *reinterpret_cast<const int*>(el2));
}

int main() {
    int n, m = 0;
    std::cin >> n >> m;
    int** Array = new int*[n];

    for (int i = 0; i < n; i++) {
        *GetppElementByOffset(Array, i) = new int(m);
        for (int j = 0; j < m; j++) {
            *GetpElementByOffset(*GetppElementByOffset(Array, i), j) = rand() % 50;
            std::cout << *GetpElementByOffset(*GetppElementByOffset(Array, i), j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        qsort(*GetppElementByOffset(Array, i), static_cast<size_t>(m), static_cast<size_t>(sizeof(int)), Comparator);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << *GetpElementByOffset(*GetppElementByOffset(Array, i), j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
