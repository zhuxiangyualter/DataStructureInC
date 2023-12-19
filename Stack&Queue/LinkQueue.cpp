/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-10.
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class LinkQueue{
private:
    struct Node{
        T data;
        Node *next;
    };
    Node *front,*rear;
public:
    //初始化
    void InitQueue(){
        front = rear = new Node;
        front->next = nullptr;
    };
    //销毁
    void DestoryQueue(){
        while (front){
            rear = front->next;
            delete front;
            front = rear;
        }
    };
    //判空
    bool Empty(){
        return front == rear;
    };
    //求长
    int Length(){
        int i = 0;
        Node *p = front;
        while (p->next){
            i++;
            p = p->next;
        }
        return i;
    };
    //取队头
    T GetHead(){
        if (Empty()){
            cout<<"队列为空"<<endl;
            exit(0);
        }
        return front->next->data;
    };
    //入队
    void EnQueue(T e){
        Node *p = new Node;
        p->data = e;
        p->next = nullptr;
        rear->next = p;
        rear = p;
    };
    //出队
    T DeQueue(){
        if (Empty()){
            cout<<"队列为空"<<endl;
            exit(0);
        }
        Node *p = front->next;
        T e = p->data;
        front->next = p->next;
        if (rear == p){
            rear = front;
        }
        delete p;
        return e;
    };
    //清空
    void Clear(){
        while (front->next){
            rear = front->next;
            delete front;
            front = rear;
        }
    };
    //遍历
    void Traverse(){
        Node *p = front->next;
        while (p){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    };
};
int main(){
    LinkQueue<int> q;
    q.InitQueue();
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.EnQueue(4);
    q.EnQueue(5);
    q.Traverse();
    cout<<q.GetHead()<<endl;
    cout<<q.DeQueue()<<endl;
    q.Traverse();
    cout<<q.Length()<<endl;
    q.Clear();
    q.Traverse();
    cout<<q.Empty()<<endl;
    q.DestoryQueue();
    return 0;
}