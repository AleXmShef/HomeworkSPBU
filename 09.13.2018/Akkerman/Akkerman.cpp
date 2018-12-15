#include <iostream>

int Akkerman(int m, int n){
     if (!m && n)
        return (n + 1);
     else if (m && !n)
            return Akkerman(m - 1, 1);
     return Akkerman(m - 1, Akkerman(m ,n - 1));
}

int main() {
    std::cout << Akkerman(5, 5);



    return 0;
}
