#include<bits/stdc++.h>
using namespace std;
void ShellSort(int a[],int n){
    int i,j,d; //声明三个整型变量i、j和d
    for (d=n/2;d>=1;d=d/2){ //初始化增量d为n的一半，每次减半
        for (i=d+1;i<=n;i++){ //从增量d+1开始遍历数组
            if (a[i]<a[i-d]){ //如果当前元素小于其距离为d的元素
                a[0]=a[i]; //将当前元素赋值给第一个元素
                for (j=i-d;j>0&&a[0]<a[j];j-=d) //从当前元素的前一个元素开始向前遍历，直到找到合适的位置插入当前元素
                    a[j+d]=a[j]; //将比当前元素大的元素向后移动d位
                a[j+d]=a[0]; //将当前元素插入到正确的位置
            }
        }
    }
}
int main() {
    int a[100];
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    ShellSort(a,n);
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    };
    return 0;
}
