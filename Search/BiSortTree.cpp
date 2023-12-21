/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-19.
*/
#include<bits/stdc++.h>
using namespace std;
//构造函数、插入元素、查找、中序遍历，并验证
template <typename T>
class BiSortTree{
private:
    struct BiTNode{
        T data;
        BiTNode *lchild,*rchild;
    };
    BiTNode *root;
public:
    BiSortTree(){
        root=NULL;
    }
    ~BiSortTree(){
        Destroy(root);
    }
    void Destroy(BiTNode *p){
        if (p!=NULL){
            Destroy(p->lchild);
            Destroy(p->rchild);
            delete p;
        }
    }
    void Insert(T key){
        Insert(root,key);
    }
    void Insert(BiTNode *&p,T key){
        if (p==NULL){
            p=new BiTNode;
            p->data=key;
            p->lchild=p->rchild=NULL;
        }
        else if (key<p->data) Insert(p->lchild,key);
        else if (key>p->data) Insert(p->rchild,key);
    }
    bool Search(T key){
        return Search(root,key);
    }
    bool Search(BiTNode *p,T key){
        if (p==NULL) return false;
        else if (key==p->data) return true;
        else if (key<p->data) return Search(p->lchild,key);
        else return Search(p->rchild,key);
    }
    void InOrder(){
        InOrder(root);
    }
    void InOrder(BiTNode *p){
        if (p!=NULL){
            InOrder(p->lchild);
            cout<<p->data<<" ";
            InOrder(p->rchild);
        }
    }
};
int main() {
    BiSortTree<int> tree;
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    tree.Insert(6);
    tree.Insert(8);
    tree.InOrder();
    cout<<endl;
    cout<<tree.Search(5)<<endl;
    cout<<tree.Search(1)<<endl;

    return 0;
};
