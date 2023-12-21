/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-21.
*/
#include<bits/stdc++.h>
using namespace std;

//输入二叉树的前序遍历序列和中序遍历序列，构造二叉树，并对构造的二叉树进行前序、中序、后序遍历
//输入：第一行输入一个整数n，表示二叉树的结点个数，接下来两行，每行n个整数，分别表示二叉树的前序遍历序列和中序遍历序列
//输出：输出三行，分别表示二叉树的前序遍历序列、中序遍历序列和后序遍历序列
//样例输入：
//7
//1 2 4 5 3 6 7
//4 2 5 1 6 3 7
//样例输出：
//1 2 4 5 3 6 7
//4 2 5 1 6 3 7
//4 5 2 6 7 3 1
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
    void PreOrder(BiTNode<T> *bt){
        if (bt){
            cout<<bt->data<<" ";
            PreOrder(bt->lchild);
            PreOrder(bt->rchild);
        }
    };
    void InOrder(BiTNode<T> *bt){
        if (bt){
            InOrder(bt->lchild);
            cout<<bt->data<<" ";
            InOrder(bt->rchild);
        }
    };
    void PostOrder(BiTNode<T> *bt){
        if (bt){
            PostOrder(bt->lchild);
            PostOrder(bt->rchild);
            cout<<bt->data<<" ";
        }
    };
    void PreOrder(){
        PreOrder(root);
    };
    void InOrder(){
        InOrder(root);
    };
    void PostOrder(){
        PostOrder(root);
    };
    void CreateBiTree(){
        CreateBiTree(root);
    };
    //由前序遍历序列和中序遍历序列构造二叉树
    void CreateBiTree(T *pre,T *in,int n,BiTNode<T> *&bt){
        if (n <= 0){
            bt = nullptr;
            return;
        }
        int k = 0;
        while (pre[0] != in[k]){
            k++;
        }
        bt = new BiTNode<T>;
        bt->data = pre[0];
        CreateBiTree(pre+1,in,k,bt->lchild);
        CreateBiTree(pre+k+1,in+k+1,n-k-1,bt->rchild);
    };
    BiTNode<T> *root;
};
int main(){
    int n;
    cin>>n;
    char pre[n],in[n];
    for (int i=0;i<n;i++){
        cin>>pre[i];
    }
    for (int i=0;i<n;i++){
        cin>>in[i];
    }
    BiTree<char> tree;
    tree.CreateBiTree(pre,in,n,tree.root);
    tree.PreOrder();
    cout<<endl;
    tree.InOrder();
    cout<<endl;
    tree.PostOrder();
    cout<<endl;
    return 0;
}