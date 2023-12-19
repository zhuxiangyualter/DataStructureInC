/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-09.
*/
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class SeqStack {
private:
    stack<T> stk;
public:
    void push(T x) {
        stk.push(x);
    }
    void pop() {
        if (!stk.empty()) {
            stk.pop();
        }
    }
    T top() {
        if (!stk.empty()) {
            return stk.top();
        }
        return -1;
    }
    bool isEmpty() {
        return stk.empty();
    }
};

string decToBase(int num, int base) {
    SeqStack<char> stk;
    string result = "";
    while (num > 0) {
        int remainder = num % base;
        if (remainder >= 10) {
            remainder += 'A' - 10;
        }
        stk.push('0' + remainder);
        num /= base;
    }
    while (!stk.isEmpty()) {
        result += stk.top();
        stk.pop();
    }
    return result;
}

int main() {
    int num, base;
    cout << "请输入十进制数：";
    cin >> num;
    cout << "请输入目标进制（2-16）：";
    cin >> base;
    if (base < 2 || base > 16) {
        cout << "进制输入错误！" << endl;
        return 1;
    }
    string result = decToBase(num, base);
    cout << "转换后的数为：" << result << endl;
    return 0;
}
// Compare this snippet from Stack%26Queue/SeqStack.cpp: