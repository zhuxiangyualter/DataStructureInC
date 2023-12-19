#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

// 生成随机对称矩阵
vector<vector<int>> generate_symmetric_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            matrix[i][j] = rand() % 10;
            matrix[j][i] = matrix[i][j];
        }
    }
    return matrix;
}

// 压缩存储对称矩阵的下三角部分到一维数组
vector<int> compress_symmetric_matrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> compressed_matrix(n * (n + 1) / 2);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            compressed_matrix[index++] = matrix[i][j];
        }
    }
    return compressed_matrix;
}

// 根据行列下标在一维数组中存取元素
int get_element(const vector<int>& compressed_matrix, int row, int col) {
    int n = static_cast<int>(sqrt(compressed_matrix.size()));
    int index = row * (row + 1) / 2 + col - row - 1;
    return compressed_matrix[index];
}

int main() {
    int n = 5;
    vector<vector<int>> matrix = generate_symmetric_matrix(n);
    vector<int> compressed_matrix = compress_symmetric_matrix(matrix);

    cout << "原始对称矩阵：" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "压缩后的一维数组：" << endl;
    for (int val : compressed_matrix) {
        cout << val << " ";
    }
    cout << endl;

    int row = 2, col = 3;
    cout << "元素(" << row << ", " << col << ")在一维数组中的值为： " << get_element(compressed_matrix, row, col) << endl;

    return 0;
}
