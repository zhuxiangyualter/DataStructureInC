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
    int a[100];
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    SelectSort(a,n);
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    };
    return 0;
}
