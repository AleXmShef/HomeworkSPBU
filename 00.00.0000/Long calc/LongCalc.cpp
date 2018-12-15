#include <vector>
#include <iostream>
#include <math.h>

class LongNumber {
protected:
    void GetNumber(long n) {
        bool flag = 1;
        int i = 0;
        std::vector<int> result;
        while(flag) {
            if (n < 10)
                flag = 0;
            int temp = n - (n/10)*10;
            std::cout << temp << std::endl;
            result.insert(result.begin(), temp);
            n -= temp;
            n /= 10;
            i++;
        }

        mpArray = result;
        mSize = i;
        mSign = 1;
    }

    LongNumber Sum(LongNumber n1, LongNumber n2) {

    }

    LongNumber Substract(LongNumber n1, LongNumber n2) {

    }

    LongNumber Multiply(LongNumber n1, LongNumber n2) {
        int n = std::max(n1.mSize, n2.mSize);
        n /= 2;
        std::vector<int> X1 = {n1.mpArray.begin(), n1.mpArray.begin() + n};
    }

    LongNumber NaiveMultiply(LongNumber n1, LongNumber n2) {

    }

    LongNumber Divide(LongNumber n1, LongNumber n2) {

    }
protected:
    std::vector<int> mpArray;
    int mSign = 1;
    int mSize = 0;
public:
    LongNumber(){};
    LongNumber(long n) {
        GetNumber(n);
    }

    void PrintNumber() {
        for (int i = 0; i < mpArray.size(); i++) {
            std::cout << mpArray[i];
        }
    }

    void operator=(long n) {
        GetNumber(n);
    }

};
