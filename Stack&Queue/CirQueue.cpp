/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-10.
*/
#include<bits/stdc++.h>
using namespace std;

class CirQueue{
private:
    int *base;
    int front,rear;
public:
    void InitQueue(){
        base = new int[100];
        front = rear = 0;
    };
    void DestoryQueue(){
        delete []base;
    };
    bool Empty(){
        return front == rear;
    };
    int Length(){
        return (rear-front+100)%100;
    };
    int GetHead(){
        if (Empty()){
            cout<<"队列为空"<<endl;
            exit(0);
        }
        return base[front];
    };
    void EnQueue(int e){
        if ((rear+1)%100 == front){
            cout<<"队列已满"<<endl;
            exit(0);
        }
        base[rear] = e;
        rear = (rear+1)%100;
    };
    int DeQueue(){
        if (Empty()){
            cout<<"队列为空"<<endl;
            exit(0);
        }
        int e = base[front];
        front = (front+1)%100;
        return e;
    };
};
int main() {
    CirQueue cirQueue;
    cirQueue.InitQueue();
    cirQueue.EnQueue(1);
    cirQueue.EnQueue(2);
    cirQueue.EnQueue(3);
    cirQueue.EnQueue(4);
    cirQueue.EnQueue(5);
    cirQueue.EnQueue(6);
    cirQueue.EnQueue(7);
    cirQueue.EnQueue(8);
    cirQueue.EnQueue(9);
    cirQueue.EnQueue(10);
    cirQueue.EnQueue(11);
    cirQueue.DeQueue();
    cirQueue.DeQueue();

}
