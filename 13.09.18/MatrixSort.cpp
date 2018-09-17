#include <iostream>

int* GetpElementByOffset(int* p, int n) {
    for (int i = 0; i < n; i++) {
        p++;
    }
    return p;
}

int main() {
    int n = 0;
    std::cin >> n;
    int* Array = new int(n);
    for (int i = 0; i < n; i++) {
        std::cin >> *GetpElementByOffset(Array, i);
    }
    
    return 0;
}
