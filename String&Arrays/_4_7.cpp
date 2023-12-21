#include<bits/stdc++.h>
using namespace std;
struct Triplet {
    int row;
    int col;
    double value;
};
void transpose(const vector<Triplet>& A, vector<Triplet>& B) {
    for (const auto& triplet : A) {
        B.push_back({triplet.col, triplet.row, triplet.value});
    }
}
void fastTranspose(const vector<Triplet>& A, vector<double>& values, vector<int>& colIndices, vector<int>& rowPointers) {
    int n = *max_element(A.begin(), A.end(), [](const Triplet& a, const Triplet& b) { return a.row < b.row; })->row + 1;
    rowPointers.resize(n + 1);
    colIndices.clear();
    values.clear();

    for (const auto& triplet : A) {
        colIndices.push_back(triplet.col);
        values.push_back(triplet.value);
    }

    partial_sum(rowPointers.begin(), rowPointers.end(), rowPointers.begin() + 1);
}
void printTriplets(const vector<Triplet>& triplets) {
    for (const auto& triplet : triplets) {
        cout << "(" << triplet.row << ", " << triplet.col << ", " << triplet.value << ")" << endl;
    }
}
int main() {
    // 输入nxm阶的稀疏矩阵A
    // ...
    int n, m;
    cout << "请输入矩阵的行数和列数：";
    cin >> n >> m;

    // 将稀疏矩阵按行优先压缩存储到三元组顺序表中
    vector<Triplet> A;
    // ...
    cout << "请输入矩阵的元素（每行一个三元组，格式为：行号 列号 值）：" << endl;
    for (int i = 0; i < n * m; ++i) {
        int row, col;
        double value;
        cin >> row >> col >> value;
        A.push_back({row, col, value});
    }
    // 使用普通转置算法求矩阵A的转置矩阵B
    vector<Triplet> B;
    transpose(A, B);
    printTriplets(B);

    // 使用快速转置算法求矩阵A的转置矩阵B
    vector<double> values;
    vector<int> colIndices;
    vector<int> rowPointers;
    fastTranspose(A, values, colIndices, rowPointers);
    printTriplets(colIndices);
    printTriplets(values);
    printTriplets(rowPointers);

    return 0;
}
