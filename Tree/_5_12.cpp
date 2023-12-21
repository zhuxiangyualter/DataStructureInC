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
private:
    BiTNode<T> *root;
public:
    BiTree(){
        root = nullptr;
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
    }
    };
    void CreateBiTreeByPreAndIn(BiTNode<T> *&bt, T *pre, T *in, int n){
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
        CreateBiTreeByPreAndIn(bt->lchild, pre + 1, in, k);
        CreateBiTreeByPreAndIn(bt->rchild, pre + k + 1, in + k + 1, n - k - 1);
    };
    void CreateBiTreeByPreAndIn(T *pre, T *in, int n){
        CreateBiTreeByPreAndIn(root, pre, in, n);
    };
    void PreOrder(BiTNode<T> *bt){
        if (bt){
            cout<<bt->data<<" ";
            PreOrder(bt->lchild);
            PreOrder(bt->r
};
int main() {
    BiTree<char> tree;
    int n;
    cin>>n;
    char pre[n],in[n];
    for (int i=0;i<n;i++){
        cin>>pre[i];
    }
    for (int i=0;i<n;i++){
        cin>>in[i];
    }
    tree.CreateBiTreeByPreAndIn(pre,in,n);
    cout<<tree.GetNodeNumByLevel(tree.root,3)<<endl;
    cout<<tree.GetLeafNodeNum(tree.root,3)<<endl;

    return 0;
}