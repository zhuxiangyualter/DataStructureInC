/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-09.
*/
// 顺序栈
#
// Created by 15708 on 2023-12-09.

ifndef DP_SEQSTACK_H
#define DP_SEQSTACK_H
class SeqStack {
private:
    int *data;
    int top;
    int maxSize;
public:
    // 构造函数
    SeqStack(int size = 100) : data(new int[size]), top(-1), maxSize(size) {}

    // 取栈顶元素
    int top() const {
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
    void push(const int& val) {
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

};
#endif //DP_SEQSTACK_H
