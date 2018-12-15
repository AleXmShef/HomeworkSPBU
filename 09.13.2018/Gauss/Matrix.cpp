#include "Matrix.h"

Matrix::Matrix (size_t pColumnHeight, size_t pRowsLenght) : mColumnHeight(pColumnHeight), mRowLenght(pRowsLenght) {
    mppArray = new float*[mColumnHeight];
    for (size_t i = 0; i < mColumnHeight; i++) {
        mppArray[i] = new float[mRowLenght];
    }
}

void Matrix::SwapRow(int Row1, int Row2) {
    float* temp = mppArray[Row1];
    mppArray[Row1] = mppArray[Row2];
    mppArray[Row2] = temp;
}

void Matrix::SwapColumn(int Col1, int Col2) {
    for (size_t i = 0; i < mColumnHeight; i++) {
        float temp = this->mppArray[i][Col1];
        this->mppArray[i][Col1] = this->mppArray[i][Col2];
        this->mppArray[i][Col2] = temp;
    }
}

void Matrix::MultiplyRow(int Row, float mult) {
    for (size_t i = 0; i < mRowLenght; i++) {
        mppArray[Row][i]*=mult;
    }
}

void Matrix::AddTwoRows(int Row1, int Row2) {
    for (size_t i = 0; i < mRowLenght; i++) {
        mppArray[Row1][i]+=mppArray[Row2][i];
    }
}

float* Matrix::ColumnMax(int Col) {
    float* result = new float[2];
    result[0] = 0;
    for (size_t i = 0; i < mColumnHeight; i++) {
        if (mppArray[i][Col] > result[0]) {
            result[0] = mppArray[i][Col];
            result[1] = i;
        }
    }
    return result;
}

float** Matrix::GetppMatrixArray() {
    return this->mppArray;
}

void Matrix::PrintMarix() {
    for (size_t i = 0; i < mColumnHeight; i++) {
        for (size_t j = 0; j < mRowLenght; j++) {
            std::cout << mppArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

size_t* Matrix::GetMatrixInfo() {
    size_t* Info = new size_t(2);
    Info[0] = mRowLenght;
    Info[1] = mColumnHeight;
    return Info;
}
