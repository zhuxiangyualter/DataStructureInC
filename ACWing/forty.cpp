/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-25.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "hellp" << endl;
    return 0;
}
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> s;
        int row_start = 0;
        int row_end = matrix.size()-1;
        int col_start = 0;
        int col_end = matrix[0].size()-1;
        while (row_start <= row_end&&col_start <= col_end){
            for (int i = 0; i < row_end; ++i) {
                s.push_back(matrix[row_start][i]);

            }
            row_start++;
            for (int i = row_start; i < col_end; ++i) {
                s.push_back(matrix[i][col_end]);

            }
            col_end--;
            if (row_start <= row_end){
                for (int i = col_end; i >=col_start-- ; i--) {
                    s.push_back(matrix[row_end][i]);
                }
                row_end--;
            }
            if (col_start <= col_end){
                for (int i = row_end; i >= row_start ; i--) {
                    s.push_back(matrix[i][col_start]);
                }
                col_start++;
            }
        }
        return s;
    }
};