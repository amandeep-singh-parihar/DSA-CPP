#include <iostream>

using namespace std;

int main() {
    // Define the size of the dense matrix
    int numRows = 4;
    int numCols = 4;

    // Create a dense matrix
    int denseMatrix[numRows][numCols] = {
        {1, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 0, 0},
        {0, 3, 0, 4}
    };

    // Count the number of non-zero elements in the dense matrix
    int numNonZero = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (denseMatrix[i][j] != 0) {
                numNonZero++;
            }
        }
    }

    // Create a 2D array to store the sparse matrix
    int sparseMatrix[numNonZero][3]; // Each row stores row index, column index, and value

    // Convert the dense matrix to a sparse matrix
    int currentRow = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int element = denseMatrix[i][j];
            if (element != 0) {
                sparseMatrix[currentRow][0] = i; // Row index
                sparseMatrix[currentRow][1] = j; // Column index
                sparseMatrix[currentRow][2] = element; // Value
                currentRow++;
            }
        }
    }

    // Print the sparse matrix
    cout << "Sparse Matrix:" << endl;
    for (int i = 0; i < numNonZero; i++) {
        cout <<sparseMatrix[i][0] << sparseMatrix[i][1] <<sparseMatrix[i][2] << endl;
    }

    return 0;
}
