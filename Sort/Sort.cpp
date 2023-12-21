/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-01.
*/
#include<bits/stdc++.h>
using namespace std;

//直接插入排序
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

//希尔排序
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
////二路归并
//// 合并两个有序数组
//void merge(vector<int>& arr, int l, int m, int r) {
//    int n1 = m - l + 1;
//    int n2 = r - m;
//
//    vector<int> L(n1), R(n2);
//    for (int i = 0; i < n1; i++) {
//        L[i] = arr[l + i];
//    }
//    for (int j = 0; j < n2; j++) {
//        R[j] = arr[m + 1 + j];
//    }
//
//    int i = 0, j = 0, k = l;
//    while (i < n1 && j < n2) {
//        if (L[i] <= R[j]) {
//            arr[k] = L[i];
//            i++;
//        } else {
//            arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < n1) {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2) {
//        arr[k] = R[j];
//        j++;
//        k++;
//    }
//}
//
//// 迭代实现的二路归并排序
//void mergeSort(vector<int>& arr) {
//    int n = arr.size();
//    for (int currSize = 1; currSize <= n - 1; currSize = 2 * currSize) {
//        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
//            int mid = min(leftStart + currSize - 1, n - 1);
//            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);
//            merge(arr, leftStart, mid, rightEnd);
//        }
//    }
//}
////非递归二路归并排序
//void mergeSort(vector<int>& arr, int l, int r) {
//    if (l >= r) {
//        return;
//    }
//    int mid = (l + r) >> 1;
//    mergeSort(arr, l, mid);
//    mergeSort(arr, mid + 1, r);
//    merge(arr, l, mid, r);
//}

int main(){
    int a[100];
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    InsertSort(a,n);
//    ShellSort(a,n);
    //BubbleSort(a,n);
    //QSort(a,1,n);
    //SelectSort(a,n);
    //HeapSort(a,n);
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

