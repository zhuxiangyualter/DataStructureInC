/**
*@author    渚相玉
*@version   v0.9.16
*@Session 链式栈
*Created by 15708 on 2023-10-10.
*/
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class LinkStack {
private:
    vector<T> elements;
    int capacity;
public:
    void InitStack();
     ~LinkStack(){

    };
    void DestoryStack(LinkStack<T>);
    bool Empty(LinkStack<T> L){
        return L.elements.empty();
    };
    int Length(LinkStack<T> L){
        return L.elements.size();
    };
    T getTop(LinkStack<T>);
    void Clear(LinkStack<T>);
    void Push(T){
    elements.push_back(T);
    };
    T Pop(T E){
        if (Empty(E)){
            cout<<"栈为空"<<endl;
            exit(0);
        }
        T e = E.elements.back();
        E.elements.pop_back();
        return e;
    };
};
int main() {
    cout << "hellp" << endl;
    return 0;
}