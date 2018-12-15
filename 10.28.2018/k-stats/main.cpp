#include <iostream>

int Partition(int* vec, int left, int right) {
    int separator = vec[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (vec[i] < separator) {
            i++;
        }
        while (vec[j] > separator) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(vec[i++], vec[j--]);
    }
    return j;
}

int kStats(int* vec, int k, int n) {
    int left = 0;
    int right = n;
    while (true) {
        int middle = Partition(vec, left, right);
        if (middle == k) {
            return vec[middle];
        } else if (k < middle) {
            right = middle;
        } else {
            k -= middle + 1;
            left = middle + 1;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    int* vec = new int[n];
    for (auto i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        vec[i] = temp;
    }
    int k;
    std::cin>>k;
    kStats(vec, k, n);
    return 0;
}
