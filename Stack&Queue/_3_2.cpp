/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-21.
*/
#include<bits/stdc++.h>
using namespace std;
//LinkStack类模板
//构造函数、析构函数、取栈顶、出栈、入栈、判空，并在主函数中验证。
template<typename T>
class LinkStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* top;
    int sizes;
public:
    LinkStack() : top(nullptr), sizes(0) {}
    ~LinkStack() {
        Node* p = top;
        while (p != nullptr) {
            Node* q = p->next;
            delete p;
            p = q;
        }
        top = nullptr;
        sizes = 0;
    }
    T getTop() const {
        if (top == nullptr) {
            throw std::runtime_error("栈空");
        }
        return top->data;
    }
    void push(T val) {
        Node* p = new Node(val);
        p->next = top;
        top = p;
        ++sizes;
    }
    void pop() {
        if (top == nullptr) {
            throw std::runtime_error("栈空");
        }
        Node* p = top;
        top = top->next;
        delete p;
        --sizes;
    }
    bool isEmpty() const {
        return top == nullptr;
    }

};
int main() {
    LinkStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.getTop() << endl;
    stack.pop();
    cout << stack.getTop() << endl;
    stack.pop();
    cout << stack.getTop() << endl;
    stack.pop();
    cout << stack.isEmpty() << endl;

    return 0;
}