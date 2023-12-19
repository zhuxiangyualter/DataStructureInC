#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 生成nxn阶的下三角矩阵
vector<vector<int>> generateLowerTriangularMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

// 将下三角矩阵按行优先压缩存储到一维数组中
vector<int> compressLowerTriangularMatrix(const vector<vector<int>>& matrix) {
    vector<int> compressedMatrix;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j <= i; j++) {
            compressedMatrix.push_back(matrix[i][j]);
        }
    }
    return compressedMatrix;
}

// 根据行列下标在一维数组中存取元素
int getElement(const vector<int>& compressedMatrix, int row, int col) {
    return compressedMatrix[row * (row + 1) / 2 + col - row - 1];
}

int main() {
    int n = 5;
    vector<vector<int>> lowerTriangularMatrix = generateLowerTriangularMatrix(n);
    vector<int> compressedMatrix = compressLowerTriangularMatrix(lowerTriangularMatrix);
    cout << "Element at (2, 3): " << getElement(compressedMatrix, 2, 3) << endl;
    return 0;
}
