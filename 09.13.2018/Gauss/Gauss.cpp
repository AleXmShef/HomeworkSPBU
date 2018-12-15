#include <iostream>

#include "Matrix.h"

class GaussSolver {
public:
    void Solve(Matrix* EqMatrix) {
        EquationMatrix = EqMatrix;
        float* Solution = new float(EquationMatrix->GetMatrixInfo()[1]);
        //EquationMatrix->PrintMarix();
        Triangulate();
        //EquationMatrix->PrintMarix();
        for (size_t i = EquationMatrix->GetMatrixInfo()[1] - 1; i >= 0; --i) {
            Solution[i] = ((*EquationMatrix)[i][EquationMatrix->GetMatrixInfo()[1]]    /  (*EquationMatrix)[i][i]);
            std::cout << "Solution: " << Solution[i] << std::endl;
            for (size_t j = 0; j < i; ++j) {
                (*EquationMatrix)[j][EquationMatrix->GetMatrixInfo()[1]] -= ((*EquationMatrix)[j][i]*Solution[i]);
            }
        }
    }
private:
    Matrix* EquationMatrix = nullptr;
    void Triangulate() {
        for (size_t i = 0; i < EquationMatrix->GetMatrixInfo()[1] - 1; ++i) {
            float* ColMax = EquationMatrix->ColumnMax(i);
            if (i != ColMax[1])
                EquationMatrix->SwapRow(ColMax[1], i);
            for (size_t j =  i + 1; j < EquationMatrix->GetMatrixInfo()[1]; ++j) {
                float mult = -1*((*EquationMatrix)[j][i]/(*EquationMatrix)[i][i]);
                float* temp = (*EquationMatrix)[i];
                EquationMatrix->MultiplyRow(i, mult);
                EquationMatrix->AddTwoRows(j, i);
                EquationMatrix->GetppMatrixArray()[i] = temp;
            }
        }
    }
};

int main(){
    size_t equation_count = 0;

    std::cout << "Input equation count" << std::endl;
    std::cin >> equation_count;

    Matrix* pEquationMatrix = new Matrix(equation_count, equation_count+1);

    for (size_t i = 0; i < equation_count; i++) {
        std::cout << "Input the coefficients of equation " << i + 1 << std::endl;
        for (size_t j = 0; j < equation_count+1; j++) {
            std::cin >> (*pEquationMatrix)[i][j];
        }
    }

    std::cout << std::endl;
    pEquationMatrix->PrintMarix();

    GaussSolver* pGaussSolver = new GaussSolver;

    pGaussSolver->Solve(pEquationMatrix);

    return 0;
}
