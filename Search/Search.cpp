/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-01.
*/
#include<bits/stdc++.h>
using namespace std;
//线性查找
int Search(int a[],int n,int key){
    int i;
    for (i=1;i<=n;i++){
        if (a[i]==key) return i;
    }
    return 0;
}
//折半查找
int BinarySearch(int a[],int n,int key){
    int low,high,mid;
    low=1;high=n;
    while (low<=high){
        mid=(low+high)/2;
        if (key<a[mid]) high=mid-1;
        else if (key>a[mid]) low=mid+1;
        else return mid;
    }
    return 0;
}
////二叉排序树
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
        else Insert(p->rchild,key);
    }
    void Delete(T key){
        Delete(root,key);
    }
    void Delete(BiTNode *&p,T key){
        if (p==NULL) return;
        else{
            if (key==p->data) DeleteNode(p);
            else if (key<p->data) Delete(p->lchild,key);
            else Delete(p->rchild,key);
        }
    }
    void DeleteNode(BiTNode *&p){
        BiTNode *q,*s;
        if (p->rchild==NULL){
            q=p;
            p=p->lchild;
            delete q;
        }
        else if (p->lchild==NULL){
            q=p;
            p=p->rchild;
            delete q;
        }
        else{
            q=p;
            s=p->lchild;
            while (s->rchild){
                q=s;
                s=s->rchild;
            }
            p->data=s->data;
            if (q!=p) q->rchild=s->lchild;
            else q->lchild=s->lchild;
            delete s;
        }
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

//散列查找
#define NULLKEY -32768
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768
typedef struct{
    int *elem;
    int count;
}HashTable;
int m=0;
int InitHashTable(HashTable *H){
    int i;
    m=HASHSIZE;
    H->count=m;
    H->elem=(int *)malloc(m*sizeof(int));
    for (i=0;i<m;i++) H->elem[i]=NULLKEY;
    return 1;
}
int Hash(int key){
    return key%m;
}
void InsertHash(HashTable *H,int key){
    int addr=Hash(key);
    while (H->elem[addr]!=NULLKEY) addr=(addr+1)%m;
    H->elem[addr]=key;
}
int SearchHash(HashTable H,int key,int *addr){
    *addr=Hash(key);
    while (H.elem[*addr]!=key){
        *addr=(*addr+1)%m;
        if (H.elem[*addr]==NULLKEY||*addr==Hash(key)) return UNSUCCESS;
    }
    return SUCCESS;
}

int main(){

}
