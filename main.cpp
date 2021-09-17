#include "laba1.h"

using namespace laba1;

int main() {
    Matrix* SpMatrix = inputMatrix();
    if (!SpMatrix) {
        std::cout << "Error! Incorrect input!" << std::endl;
    }
    else {
        PrintOldMatrix(SpMatrix);
        SortingMatrix(SpMatrix);
        PrintChangedMatrix(SpMatrix);
        delete[] SpMatrix->cells;
        delete SpMatrix;
    }
    return 0;
}
