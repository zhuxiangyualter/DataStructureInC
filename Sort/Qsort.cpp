/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-19.
*/
#include<bits/stdc++.h>
using namespace std;
//快速排序
int Partition(int a[],int low,int high){
    int pivotkey; //声明一个整型变量pivotkey作为基准值
    pivotkey=a[low]; //将基准值设为数组的第一个元素
    while (low<high){ //当low小于high时，继续循环
        while (low<high&&a[high]>=pivotkey) high--; //从数组的最后一个元素开始向前遍历，直到找到一个小于等于基准值的元素
        swap(a[low],a[high]); //交换当前元素和找到的元素的位置
        while (low<high&&a[low]<=pivotkey) low++; //从数组的第一个元素开始向后遍历，直到找到一个大于等于基准值的元素
        swap(a[low],a[high]); //交换当前元素和找到的元素的位置
    }
    return low; //返回基准值的位置
}
//快速排序
void QSort(int a[],int low,int high){
    int pivot; //声明一个整型变量pivot作为基准值
    if (low<high){ //当low小于high时，继续循环
        pivot=Partition(a,low,high); //调用Partition函数，获取基准值的位置
        QSort(a,low,pivot-1); //对基准值左边的子数组进行快速排序
        QSort(a,pivot+1,high); //对基准值右边的子数组进行快速排序
    }
}
int main() {
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    QSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
