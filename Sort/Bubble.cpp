/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-19.
*/
#include<bits/stdc++.h>
using namespace std;
//冒泡排序
void BubbleSort(int a[],int n){
    int i,j; //声明两个整型变量i和j
    bool flag; //声明一个布尔型变量flag
    for (i=1;i<n;i++){ //从第二个元素开始遍历数组
        flag=false; //初始化flag为false
        for (j=n;j>=i+1;j--){ //从数组的最后一个元素开始向前遍历，直到第i个元素
            if (a[j]<a[j-1]){ //如果当前元素小于前一个元素
                swap(a[j],a[j-1]); //交换当前元素和前一个元素的位置
                flag=true; //将flag设为true，表示发生了交换
            }
        }
        if (!flag) break; //如果没有发生交换，说明数组已经有序，可以提前结束排序
    }
}
int main() {
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    BubbleSort(a,10);
    return 0;
}