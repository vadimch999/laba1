#include "laba1.h"

namespace laba1 {
    int inputNumber(const char* msg, int &numb) {
        const char* errmsg = "";
        do {
            std::cout << errmsg << std::endl;
            std::cout << msg << std::endl;
            errmsg = "You are wrong; Repeat, please!";
            if (getNum(numb) < 0) {
                return 1;
            }
        } while (numb < 0);
        return 0;
    }

    bool isDown(int numb) {
        int m = numb % 10;
        while (numb /= 10) {
            if (m > numb % 10) {
                return false;
            }
            m = numb % 10;
        }
        return true;
    }

    Matrix* inputMatrix() {
        const char* errmsg = "";
        Matrix* SparseMatrix = nullptr;
        SparseMatrix = new Matrix;
        if (inputNumber("Enter the number of the lines: ", SparseMatrix->n)) return nullptr;
        if (inputNumber("Enter the number of the columns: ", SparseMatrix->m)) return nullptr;
        if (inputNumber("Enter the number of the elements: ", SparseMatrix->count)) return nullptr;
        if (SparseMatrix->n * SparseMatrix->m < SparseMatrix->count) return nullptr;

        try {
            SparseMatrix->cells = new Cell[SparseMatrix->count];
        }
        catch (std::bad_alloc &ba){
            std::cout << "Too many elements!" << ba.what() << std::endl;
            return nullptr;
        }
        int it = 0;
        bool next;
        while (it < SparseMatrix->count) {
            next = true;
            if (inputNumber("Enter the index of the line: ", SparseMatrix->cells[it].x_pos) || SparseMatrix->cells[it].x_pos > SparseMatrix->n) {
                delete[] SparseMatrix->cells;
                delete SparseMatrix;
                return nullptr;
            }
            if (inputNumber("Enter the index of the column: ", SparseMatrix->cells[it].y_pos) || SparseMatrix->cells[it].y_pos > SparseMatrix->m) {
                delete[] SparseMatrix->cells;
                delete SparseMatrix;
                return nullptr;
            }
            if (inputNumber("Enter the value of the element: ", SparseMatrix->cells[it].value)) {
                delete[] SparseMatrix->cells;
                delete SparseMatrix;
                return nullptr;
            }
            for (int j = 0; j < it; j++) {
                if (SparseMatrix->cells[j].x_pos == SparseMatrix->cells[it].x_pos && SparseMatrix->cells[j].y_pos == SparseMatrix->cells[it].y_pos) {
                    std::cout << ("Error! That element is already exist!") << std::endl;
                    next = false;
                    break;
                }
            }
            if (next) it++;
        }
        for (int i = SparseMatrix->count - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (SparseMatrix->cells[j].x_pos > SparseMatrix->cells[j + 1].x_pos) {
                    Cell temp = SparseMatrix->cells[j];
                    SparseMatrix->cells[j] = SparseMatrix->cells[j + 1];
                    SparseMatrix->cells[j + 1] = temp;
                }
            }
        }
        return SparseMatrix;
    }

    void PrintOldMatrix(Matrix* SparseMatrix) {
        std::cout << "Old Matrix: " << std::endl;
        bool show = false;
        int index = 0;
        for (int i = 1; i <= SparseMatrix->n; i++) {
            for (int j = 1; j <= SparseMatrix->m; j++) {
                while (index <= SparseMatrix->count - 1) {
                    if (SparseMatrix->cells[index].x_pos == i && SparseMatrix->cells[index].y_pos == j) {
                        std::cout << SparseMatrix->cells[index].value << " ";
                        show = true;
                        break;
                    }
                    index++;
                }
                if (!show) std::cout << "0 ";
                show = false;
                index = 0;
            }
            std::cout << std::endl;
        }
    }

    void PrintChangedMatrix(Matrix* SparseMatrix) {
        std::cout << "New Matrix: " << std::endl;
      /*for (int i = 0; i < SparseMatrix->count; i++) {
            std::cout << SparseMatrix->cells[i].x_pos << " " << SparseMatrix->cells[i].y_pos << " " << SparseMatrix->cells[i].value  << " " << isRise(SparseMatrix->cells[i].value) << isDown(SparseMatrix->cells[i].value) << std::endl;
        }
        std::cout << std::endl << std::endl; */
        int count = 0, index = 0;
        for (int i = 1; i <= SparseMatrix->n; i++) {
            while (SparseMatrix->cells[index].x_pos == i) {
                count++;
                std::cout << SparseMatrix->cells[index].value << " ";
                index = (index + 1) % SparseMatrix->count;
            }
            for (int j = 1; j <= SparseMatrix->m - count; j++) std::cout << "0 ";
            count = 0;
            std::cout << std::endl;
        }
    }

    bool isRise(int numb) {
        int m = numb % 10;
        while (numb /= 10) {
            if (m < numb % 10) {
                return false;
            }
            m = numb % 10;
        }
        return true;
    }

    bool CompareElements(int &first, int &second) {
        bool show1 = isRise(first), show2 = isRise(second);
        if (!show1 && show2) return true;
        else {
            if (!show1 && !isDown(first) && isDown(second)) return true;
        }
        return false;
    }

    void SortingMatrix(Matrix *SparseMatrix) {
        for (int i = SparseMatrix->count - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (CompareElements(SparseMatrix->cells[j].value, SparseMatrix->cells[j + 1].value) && (SparseMatrix->cells[j].x_pos == SparseMatrix->cells[j + 1].x_pos)) {
                    Cell temp = SparseMatrix->cells[j];
                    SparseMatrix->cells[j] = SparseMatrix->cells[j + 1];
                    SparseMatrix->cells[j + 1] = temp;
                }
            }
        }
    }
}