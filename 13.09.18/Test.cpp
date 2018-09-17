#include <iostream>
#include <cstdlib>

int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
  return ( *(int*)x1 - *(int*)x2 );              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main ()
{
    int n = 0;
    std::cin >> n;
    int* vector = new int(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vector[i];
    }
    qsort(vector, 6, sizeof(int), compare);      // сортируем массив чисел
    for ( int ix = 0; ix < 6; ix++)
        std::cout << vector[ix] << " ";
    return 0;
}
