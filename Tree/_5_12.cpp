/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-21.
*/
#include<bits/stdc++.h>
using namespace std;
//求二叉树第k层的结点个数
// 第K层叶子结点个数
template <typename T>
struct BiTNode{
    T data;
    BiTNode<T> *lchild,*rchild;
};
template <typename T>
class BiTree{
public:
    BiTree(){
        root = nullptr;
    };
    //构造函数
    BiTree(T data){
        root = new BiTNode<T>;
        root->data = data;
        root->lchild = nullptr;
        root->rchild = nullptr;
    };

    //求二叉树第k层的结点个数
    int GetNodeNumByLevel(BiTNode<T> *bt, int k){
        if (bt == nullptr || k < 1){
            return 0;
        }
        if (k == 1){
            return 1;
        }
        int numLeft = GetNodeNumByLevel(bt->lchild, k - 1);
        int numRight = GetNodeNumByLevel(bt->rchild, k - 1);
        return numLeft + numRight;
    };
    //求二叉树第K层叶子结点个数
    int GetLeafNodeNum(BiTNode<T> *bt,int k){
        if (bt == nullptr || k < 1){
            return 0;
        }
        if(k==1){
            if(bt->lchild== nullptr&&bt->rchild== nullptr){
                return 1;
            } else{
                return 0;
            }
        }
        int numLeft = GetLeafNodeNum(bt->lchild, k - 1);
        int numRight = GetLeafNodeNum(bt->rchild, k - 1);
        return numLeft + numRight;
    };

    BiTNode<T> *root;
};
//求二叉树第k层的结点个数和叶子结点个数
int main() {
    BiTree<int> biTree(1);
    biTree.root->lchild = new BiTNode<int>;
    biTree.root->rchild = new BiTNode<int>;
    biTree.root->lchild->data = 2;
    biTree.root->rchild->data = 3;
    biTree.root->lchild->lchild = new BiTNode<int>;
    biTree.root->lchild->rchild = new BiTNode<int>;
    biTree.root->lchild->lchild->data = 4;
    biTree.root->lchild->rchild->data = 5;
    biTree.root->rchild->lchild = new BiTNode<int>;
    biTree.root->rchild->rchild = new BiTNode<int>;
    biTree.root->rchild->lchild->data = 6;
    biTree.root->rchild->rchild->data = 7;
    cout << "第2层结点个数：" << biTree.GetNodeNumByLevel(biTree.root, 2) << endl;

    cout << "第2层叶子结点个数：" << biTree.GetLeafNodeNum(biTree.root, 2) << endl;
    cout<<"王观祥"<<endl;

    return 0;
}
