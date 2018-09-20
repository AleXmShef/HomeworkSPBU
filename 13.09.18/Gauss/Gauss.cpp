#include <iostream>

class Matrix {
public:
    Matrix(size_t x, size_t y):RowLenght(y), ColumnHeight(x) {
        mppArray = new float*[x];
        for (size_t i = 0; i < x; i++) {
            mppArray[i] = new float[y];
        }
    }
    void SwapRow(int Row1, int Row2) {
        float* temp = this->mppArray[Row1];
        this->mppArray[Row1] = this->mppArray[Row2];
        this->mppArray[Row2] = temp;
    }
    void SwapColumn(int Col1, int Col2) {
        for (size_t i = 0; i < ColumnHeight; i++) {
            float temp = this->mppArray[i][Col1];
            this->mppArray[i][Col1] = this->mppArray[i][Col2];
            this->mppArray[i][Col2] = temp;
        }
    }
    void MultiplyRow(int Row, float mult) {
        for (size_t i = 0; i < RowLenght; i++) {
            mppArray[Row][i]*=mult;
        }
    }
    void AddTwoRows(int Row1, int Row2) {
        for (size_t i = 0; i < RowLenght; i++) {
            mppArray[Row1][i]+=mppArray[Row2][i];
        }
    }
    float* ColumnMax(int Col) {
        float* result = new float[2];
        result[0] = 0;
        for (size_t i = 0; i < ColumnHeight; i++) {
            if (mppArray[i][Col] > result[0]) {
                result[0] = mppArray[i][Col];
                result[1] = i;
            }
        }
        return result;
    }
    float** GetppMatrixArray() {
        return this->mppArray;
    }
    void PrintMarix() {
        for (size_t i = 0; i < ColumnHeight; i++) {
            for (size_t j = 0; j < RowLenght; j++) {
                std::cout << mppArray[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    size_t* GetMatrixInfo() {
        size_t* Info = new size_t(2);
        Info[0] = this->RowLenght;
        Info[1] = this->ColumnHeight;
        return Info;
    }
private:
    size_t ColumnHeight;
    size_t RowLenght;
    float** mppArray;
};

class GaussSolver {
public:
    void Solve(Matrix* EqMatrix) {
        EquationMatrix = EqMatrix;
        float* Solution = new float(EquationMatrix->GetMatrixInfo()[1]);
        Triangulate();
        EquationMatrix->PrintMarix();
        for (size_t i = EquationMatrix->GetMatrixInfo()[1] - 1; i >= 0; --i) {
            Solution[i] = EquationMatrix->GetppMatrixArray()[i][EquationMatrix->GetMatrixInfo()[1]]/EquationMatrix->GetppMatrixArray()[i][i];
            std::cout << "Solution: " << Solution[i] << std::endl;
            for (size_t j = 0; j < i; ++j) {
                EquationMatrix->GetppMatrixArray()[j][EquationMatrix->GetMatrixInfo()[1]]-=((EquationMatrix->GetppMatrixArray()[j][i])*Solution[i]);
            }
        }
    }
private:
    Matrix* EquationMatrix = nullptr;
    void Triangulate() {
        for (size_t i = 0; i < EquationMatrix->GetMatrixInfo()[1] - 1; ++i) {
            float* ColMax = EquationMatrix->ColumnMax(i);
            std::cout << "ColMax for column " << i + 1 << " is " << ColMax[0] << std::endl;
            if (i != ColMax[1])
                EquationMatrix->SwapRow(ColMax[1], i);
            for (size_t j =  i + 1; j < EquationMatrix->GetMatrixInfo()[1]; ++j) {
                float mult = -1*((EquationMatrix->GetppMatrixArray()[j][i])/(EquationMatrix->GetppMatrixArray()[i][i]));
                float* temp = EquationMatrix->GetppMatrixArray()[i];
                EquationMatrix->MultiplyRow(i, mult);
                std::cout << "Multiplying Row " << i + 1 << " by " << mult << std::endl;
                EquationMatrix->AddTwoRows(j, i);
                EquationMatrix->GetppMatrixArray()[i] = temp;
                EquationMatrix->PrintMarix();
            }
        }
    }
};

int main(){
    size_t equation_count = 0;

    std::cout << "Input equation count" << std::endl;
    std::cin >> equation_count;

    Matrix* EquationMatrix = new Matrix(equation_count, equation_count+1);

    for (size_t i = 0; i < equation_count; i++) {
        std::cout << "Input the coefficients of equation " << i + 1 << std::endl;
        for (size_t j = 0; j < equation_count+1; j++) {
            std::cin >> EquationMatrix->GetppMatrixArray()[i][j];
        }
    }

    EquationMatrix->PrintMarix();

    GaussSolver* mGaussSolver = new GaussSolver;

    mGaussSolver->Solve(EquationMatrix);

    return 0;
}
