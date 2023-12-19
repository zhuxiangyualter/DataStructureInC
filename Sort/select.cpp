/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-19.
*/
#include<bits/stdc++.h>
using namespace std;
//简单选择排序
void SelectSort(int a[],int n){
    int i,j,k; //声明三个整型变量i、j和k
    for (i=1;i<=n;i++){ //从第二个元素开始遍历数组
        k=i; //将k设为当前元素的下标
        for (j=i+1;j<=n;j++){ //从当前元素的下一个元素开始向前遍历，直到最后一个元素
            if (a[j]<a[k]) k=j; //如果找到一个更小的元素，将k设为该元素的下标
        }
        if (k!=i) swap(a[i],a[k]); //如果k不等于当前元素的下标，交换当前元素和找到的元素的位置
    }
}
int main() {
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    SelectSort(a,10);
    for (int i = 0; i < 10; ++i) {
        cout<<a[i]<<" ";
    }
    cout << "hellp" << endl;
    return 0;
}