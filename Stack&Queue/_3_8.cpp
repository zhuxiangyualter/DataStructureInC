#include <iostream>
#include <stack>
#include <string>
#include <sstream>

template <typename T>
class SeqStack {
private:
    std::stack<T> stk;
public:
    void push(const T& x) {
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
        return T();
    }
    bool empty() {
        return stk.empty();
    }
};

int main() {
    std::string postfix = "89+60-12*8";
    SeqStack<int> stk;
    std::istringstream iss(postfix);
    char ch;
    while (iss >> ch) {
        if (ch >= '0' && ch <= '9') {
            stk.push(ch - '0');
        } else {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            switch (ch) {
                case '+': stk.push(a + b); break;
                case '-': stk.push(a - b); break;
                case '*': stk.push(a * b); break;
                case '/': stk.push(a / b); break;
            }
        }
    }
    std::cout << stk.top() << std::endl;
    return 0;
}
