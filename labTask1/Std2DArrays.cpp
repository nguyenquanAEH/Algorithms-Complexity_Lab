//Surename Nguyen - Implementation method: SW HOR

#include "Std2DArrays.h"
#include <iostream>

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr,
    int rows, int columns)
{
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    int startValue = 1;
    // i goes from 0 (bottom row) to rows-1 (top row),
    // but we'll fill the array from the bottom up.
    for (int i = 0; i < rows; i++) {
        int realRow = rows - 1 - i;  // bottom row = rows-1, next row up = rows-2, etc.

        if (i % 2 == 0) {
            // Even row (from the bottom) → fill left to right
            for (int j = 0; j < columns; j++) {
                arr[realRow][j] = startValue++;
            }
        }
        else {
            // Odd row (from the bottom) → fill right to left
            for (int j = columns - 1; j >= 0; j--) {
                arr[realRow][j] = startValue++;
            }
        }
    }
}


void printArray(const std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
