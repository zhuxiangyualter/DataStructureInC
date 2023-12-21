#include<bits/stdc++.h>
using namespace std;
void InsertSort(int a[],int n){
    int i,j; //声明两个整型变量i和j
    for (i=2;i<=n;i++){ //从第二个元素开始遍历数组
        if (a[i]<a[i-1]){ //如果当前元素小于前一个元素
            a[0]=a[i]; //将当前元素赋值给第一个元素
            for (j=i-1;a[0]<a[j];j--) //从当前元素的前一个元素开始向前遍历，直到找到合适的位置插入当前元素
                a[j+1]=a[j]; //将比当前元素大的元素向后移动一位
            a[j+1]=a[0]; //将当前元素插入到正确的位置
        }
    }
}
int main() {
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int arr[] = {5, 3, 8, 4, 2};

    InsertSort(arr,5);
    for (int i = 0; i < 5; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}