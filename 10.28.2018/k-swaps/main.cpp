#include <iostream>

int search(bool *used, int key, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        if (!used[i]) {
            key--;
        }
        if (key == 0)
            return i;
    }
    return 0;
}

void kSwaps(int n, int k) {
    int key, value;
    bool *used = new bool[n + 1];
    int *fact = new int[n];
    int *ans = new int[n];
    for (size_t i = 0; i <= n; i++) {
        used[i] = 0;
    }
    fact[n - 1] = 1;
    for (size_t i = n - 2; i > 0; i--) {
        fact[i] = fact[i + 1]*(n - i - 1);
    }
    k--;
    for (size_t i = 0; i < n; i++) {
        key = k / fact[i];
        value = search(used, key + 1, n);
        ans[i] = value;
        used[value] = 1;
        k = k % fact[i];
    }
    for (size_t i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }
}

int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    kSwaps(n, k);

    system("pause");
    return 0;
}
