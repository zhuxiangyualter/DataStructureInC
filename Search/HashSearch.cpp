/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-19.
*/
#include<bits/stdc++.h>
using namespace std;
//散列查找
#define NULLKEY -32768 // 定义空键值为-32768
#define SUCCESS 1 // 定义成功返回值为1
#define UNSUCCESS 0 // 定义失败返回值为0
#define HASHSIZE 12 // 定义哈希表大小为12
#define NULLKEY -32768 // 再次定义空键值为-32768，避免重复定义
typedef struct{ // 定义哈希表结构体
    int *elem; // 指向整型数组的指针
    int count; // 哈希表中元素个数
}HashTable; // 结束结构体定义
int m=0; // 初始化哈希表大小为0
int InitHashTable(HashTable *H){ // 初始化哈希表函数
    int i; // 定义循环变量i
    m=HASHSIZE; // 设置哈希表大小为HASHSIZE
    H->count=m; // 设置哈希表中元素个数为m
    H->elem=(int *)malloc(m*sizeof(int)); // 分配内存空间给哈希表元素数组
    for (i=0;i<m;i++) H->elem[i]=NULLKEY; // 将哈希表元素数组初始化为空键值
    return 1; // 返回成功标志
}
int Hash(int key){ // 哈希函数
    return key%m; // 返回key对m取模的结果
}
void InsertHash(HashTable *H,int key){ // 插入哈希表函数
    int addr=Hash(key); // 计算key的哈希地址
    while (H->elem[addr]!=NULLKEY) addr=(addr+1)%m; // 如果该地址已存在元素，则向后查找下一个地址
    H->elem[addr]=key; // 将key插入到找到的地址中
}
int SearchHash(HashTable H,int key,int *addr){ // 搜索哈希表函数
    *addr=Hash(key); // 计算key的哈希地址
    while (H.elem[*addr]!=key){ // 如果该地址的元素不是key，则向后查找下一个地址
        *addr=(*addr+1)%m;
        if (H.elem[*addr]==NULLKEY||*addr==Hash(key)) return UNSUCCESS; // 如果找到了空键值或者回到了原地址，则返回失败标志
    }
    return SUCCESS; // 如果找到了key，则返回成功标志
}
int main(){
    HashTable H; // 声明一个哈希表
    int i,addr; // 声明循环变量i和哈希地址addr
    int a[12]={12,67,56,16,25,37,22,29,15,47,48,34}; // 声明一个整型数组a
    InitHashTable(&H); // 初始化哈希表
    for (i=0;i<m;i++) InsertHash(&H,a[i]); // 将数组a中的元素插入哈希表
    SearchHash(H,22,&addr); // 搜索哈希表中元素22
    cout<<H.elem[addr]<<endl; // 输出搜索到的元素
    return 0; // 返回0
}
