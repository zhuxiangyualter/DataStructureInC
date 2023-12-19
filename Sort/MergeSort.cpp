#include <iostream>
using namespace std;

// 合并两个有序数组
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    int L[n1], R[n2];

    // 拷贝数据到临时数组
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i]; // 拷贝左边有序数组的元素
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // 拷贝右边有序数组的元素

    // 合并临时数组到原数组
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // 将左边数组的元素放入原数组
            i++;
        }
        else {
            arr[k] = R[j]; // 将右边数组的元素放入原数组
            j++;
        }
        k++;
    }

    // 拷贝剩余元素
    while (i < n1) {
        arr[k] = L[i]; // 将剩余的左边数组的元素放入原数组
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j]; // 将剩余的右边数组的元素放入原数组
        j++;
        k++;
    }
}

// 非递归实现的二路归并排序
void mergeSort(int arr[], int n) {
    int currentSize;// 当前归并的数组长度
    int leftStart;// 左边数组的起始位置

    // 不断将数组分为两部分进行归并，直到步长大于等于n
    for (currentSize = 1; currentSize <= n-1; currentSize = 2*currentSize) {
        // 每次归并的两个子数组的起始位置
        for (leftStart = 0; leftStart < n-1; leftStart += 2*currentSize) {
            int mid = min(leftStart + currentSize - 1, n-1); // 计算中间位置
            int rightEnd = min(leftStart + 2*currentSize - 1, n-1); // 计算右边数组的结束位置

            // 合并两个子数组
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

// 打印数组元素
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "原始数组：" << endl;
    printArray(arr, n);

    mergeSort(arr, n);

    cout << "排序后的数组：" << endl;
    printArray(arr, n);

    return 0;
}
