#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <tuple>

using namespace std;

// 输入nxm阶的稀疏矩阵A，将稀疏矩阵按行优先压缩存储到三元组顺序表中
void compressSparseMatrix(const vector<vector<int>>& A, vector<tuple<int, int, int>>& tripletList) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] != 0) {
                tripletList.push_back(make_tuple(i, j, A[i][j]));
            }
        }
    }
}

// 输出三元组顺序表
void printTripletList(const vector<tuple<int, int, int>>& tripletList) {
    cout << "三元组顺序表为： ";
    for (const auto& t : tripletList) {
        cout << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ") ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "请输入矩阵的阶数和列数： ";
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = rand() % 10;
        }
    }
    vector<tuple<int, int, int>> tripletList;
    compressSparseMatrix(A, tripletList);
    printTripletList(tripletList);
    return 0;
}
