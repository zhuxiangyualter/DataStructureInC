#include<bits/stdc++.h>
using namespace std;
//堆排序
void Sift(int a[],int low,int high){
    int i=low,j=2*i; //声明两个整型变量i和j，初始值为low和2*low
    int temp=a[i]; //声明一个整型变量temp，用于存储要交换的元素
    while (j<=high){ //当j小于等于high时，继续循环
        if (j<high&&a[j]<a[j+1]) j++; //如果j小于high且a[j]小于a[j+1]，将j加1
        if (temp<a[j]){ //如果temp小于a[j]
            a[i]=a[j]; //将a[j]赋值给a[i]
            i=j; //将i设为j
            j=2*i; //将j设为2*i
        }
        else break; //否则跳出循环
    }
    a[i]=temp; //将temp赋值给a[i]
}

//堆排序
void HeapSort(int a[],int n){
    int i;
    for (i=n/2;i>=1;i--)
        Sift(a,i,n);
    for (i=n;i>=2;i--){
        swap(a[1],a[i]);
        Sift(a,1,i-1);
    }
}
int main() {
    int a[100];
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    HeapSort(a,n);
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    };
    return 0;
}
