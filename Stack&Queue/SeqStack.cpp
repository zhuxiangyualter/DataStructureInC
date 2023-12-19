/**
*@author    渚相玉
*@version   v0.9.16
*@Session   顺序栈
*Created by 15708 on 2023-10-10.
*/
#include <iostream>
#include <vector>

using namespace  std;
template <typename T>
class SeqStack {
private:
    vector<T> data;
    int topIndex;
    int maxSize;

public:
    // 构造函数
    SeqStack(int size = 100) : data(size), topIndex(-1), maxSize(size) {}

    // 取栈顶元素
    T top() const {
        if (isEmpty()) {
            cerr<< "Error: stack is empty\n";
            exit(EXIT_FAILURE);
        }

        return data[topIndex];
    }

    // 出栈
    void pop() {
        if (isEmpty()) {
             cerr << "Error: stack is empty\n";
            exit(EXIT_FAILURE);
        }

        topIndex--;
    }

    // 入栈
    void push(const T& val) {
        if (isFull()) {
             cerr << "Error: stack is full\n";
            exit(EXIT_FAILURE);
        }

        topIndex++;
        data[topIndex] = val;
    }

    // 判空
    bool isEmpty() const { return topIndex == -1; }

    // 判满
    bool isFull() const { return topIndex == maxSize - 1; }

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
};

int main() {
    SeqStack<int> stk(5);
    SeqStack<char> skk;
    // 入栈
    stk.push(1);
    stk.push(2);
    stk.push(3);

    // 取栈顶元素并出栈
     cout << "Top element: " << stk.top() <<  endl;
    stk.pop();

    // 入栈
    stk.push(4);
    stk.push(5);

    // 判满
    if (stk.isFull()) {
         cout << "Stack is full\n";
    }

    // 出栈并遍历
    while (!stk.isEmpty()) {
         cout << stk.top() << " ";
        stk.pop();
    }
     cout <<  endl;
    string result = skk.decToBase(10, 2);
    cout<< result << endl;

    return 0;
}
