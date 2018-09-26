#include <iostream>

class Matrix{
public:
    Matrix (size_t pColumnHeight, size_t pRowsLenght);

    void SwapRow(int Row1, int Row2);

    void SwapColumn(int Col1, int Col2);

    void MultiplyRow(int Row, float mult);

    void AddTwoRows(int Row1, int Row2);

    float* ColumnMax(int Col);

    float* operator [] (size_t Row) {
        return mppArray[Row];
    }

    float** GetppMatrixArray();

    void PrintMarix();

    size_t* GetMatrixInfo();

private:
    size_t mColumnHeight;
    size_t mRowLenght;
    float** mppArray = nullptr;
};
