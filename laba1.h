#ifndef LABA1_LABA1_H
#define LABA1_LABA1_H

#include <iostream>

namespace laba1 {
    typedef struct Cell {
        int x_pos;
        int y_pos;
        int value;
    } Cell;

    typedef struct Matrix {
        int n;
        int m;
        int count;
        Cell* cells;
    } Matrix;

    template <typename T>
    int getNum (T &a){
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    };

    Matrix* inputMatrix();
    void PrintOldMatrix(Matrix* SparseMatrix);
    int inputNumber(const char* msg, int &numb);
    void PrintChangedMatrix(Matrix* SparseMatrix);
    bool CompareElements(int &first, int &second);
    bool isRise(int numb);
    void SortingMatrix(Matrix *SparseMatrix);
    bool isDown(int numb);

}

#endif
