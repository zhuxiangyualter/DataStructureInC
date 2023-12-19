#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 生成nxn阶三对角矩阵
vector<vector<int>> generateTridiagonalMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - j) <= 1) {
                matrix[i][j] = rand() % 10;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

// 按行优先压缩存储三对角矩阵
vector<int> compressTridiagonalMatrix(const vector<vector<int>>& matrix) {
    vector<int> compressedMatrix;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (abs(i - j) <= 1) {
                compressedMatrix.push_back(matrix[i][j]);
            }
        }
    }
    return compressedMatrix;
}

int main() {
    int n;
    cout << "请输入矩阵的阶数： ";
    cin >> n;
    vector<vector<int>> matrix = generateTridiagonalMatrix(n);
    vector<int> compressedMatrix = compressTridiagonalMatrix(matrix);
    cout << "压缩后的三对角矩阵为： ";
    for (int i = 0; i < compressedMatrix.size(); i++) {
        cout << compressedMatrix[i] << " ";
    }
    cout << endl;
    return 0;
}
