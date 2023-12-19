/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-19.
*/
#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int a[], int n, int key) {
    int low, high, mid; // 定义三个整型变量，分别表示低位、高位和中间位置
    low = 1; // 初始化低位为1
    high = n; // 初始化高位为数组长度n
    while (low <= high) { // 当低位小于等于高位时，执行循环
        mid = (low + high) / 2; // 计算中间位置，取低位和高位的平均值
        if (key < a[mid]) high = mid - 1; // 如果关键字小于中间位置的元素，将高位设置为中间位置减1
        else if (key > a[mid]) low = mid + 1; // 如果关键字大于中间位置的元素，将低位设置为中间位置加1
        else return mid; // 如果关键字等于中间位置的元素，返回中间位置
    }
    return 0; // 如果循环结束仍未找到关键字，返回0
}

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    cout << BinarySearch(a, 10, 5) << endl;

    cout << "hellp" << endl;
    return 0;
}