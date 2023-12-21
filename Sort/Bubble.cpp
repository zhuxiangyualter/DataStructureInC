#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int a[], int n) {
    int i, j;
    bool flag;
    for (i = 1; i < n; i++) {
        flag = false;
        for (j = n; j >= i + 1; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

int main() {
    int a[100];
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    BubbleSort(a,n);
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    };
    return 0;
}
