#include <iostream>
using namespace std;

void josephus(int n, int m) {
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    int cnt = n;
    int j = 0;
    while (cnt > 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] != 0)
                j++;
            if (j == m) {
                j = 0;
                cout<<a[i]<<"  ";
                a[i] = 0;
                cnt--;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            cout << endl<<a[i] << endl;
}

int main() {
    int n, m;
    cout << "n=";
    cin >> n;
    cout << "m=";
    cin >> m;
    josephus(n, m);
    return 0;
}
