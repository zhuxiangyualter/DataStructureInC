#include<iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int** a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    //输入邻接矩阵
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    //选择一个起始点，这里以第3个小区为起始点，即C小区
    int start = 2;//从第2个小区开始，即C小区
    int sum = a[start][1] + a[start][2] + a[start][3];//计算起始点到其他三个小区的距离之和
    int min = sum;//初始化最小值为sum
    int index = start;//记录最小值所在的起始点编号
    //遍历所有可能的起始点，找到距离之和最小的起始点
    for(int i = start+1; i < n; i++) {
        sum = a[i][1] + a[i][2] + a[i][3];//计算当前起始点到其他三个小区的距离之和
        if(sum < min) {//如果当前距离之和小于最小值，更新最小值和起始点编号
            min = sum;
            index = i;
        }
    }
    cout << "最短路径是从第" << index+1 << "个小区到第" << n << "个小区，距离为：" << min << "。"<<endl;
    return 0;
}
