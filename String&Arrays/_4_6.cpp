#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// 生成nxn阶三对角矩阵
vector<double> generateTridiagonalMatrix(int n) {
    vector<double> matrix(n * (n + 1) / 2, 0);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            matrix[index] = rand() % 100; // 随机生成0-99之间的数
            index++;
        }
    }
    return matrix;
}

// 根据行列下标在一维数组中存取元素
double getElement(const vector<double>& matrix, int row, int col) {
    int n = static_cast<int>(sqrt(matrix.size()));
    if (row < 0 || row >= n || col < 0 || col >= n) {
        throw out_of_range("行列下标越界");
    }
    int index = row * (n + 1) - row * (row + 1) / 2 + col - row;
    return matrix[index];
}
// 遍历并输出矩阵中的所有元素
void printMatrix(const vector<double>& matrix) {
    int n = static_cast<int>(sqrt(matrix.size()));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << getElement(matrix, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    vector<double> matrix = generateTridiagonalMatrix(n);

    cout << "三对角矩阵：" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << getElement(matrix, i, j) << " ";
        }
        cout << endl;
    }
    printMatrix(matrix);
    cout << "元素(1, 1): " << getElement(matrix, 1, 1) << endl;
    cout << "元素(2, 0): " << getElement(matrix, 2, 0) << endl;

    return 0;
}
