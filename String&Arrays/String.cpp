/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-10.
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
typedef struct Chunk{
    char ch[MAX];
    struct Chunk *next;
}Chunk;
typedef struct {
    Chunk *head,*tail;  //  头尾指针
    int curlen;  //length
}LString;   //块链结构
int BF(char a[],char t[]){
    int start = 0;
    int i=0,j=0;
    while ((a[i]!='\0')&&(t[j]!='\0')){
        if (a[i] ==t[j]){
                    i++;j++;
                }
                else {start++;i=start;j=0;}
    }
    if(t[j]=='\0')
        return start++;
    else return 0;
}
int index_BF(LString s,LString t){
    int i=1,j=1;
    while (i<=s.curlen&&j<=t.curlen){
        if ()
    }
}
int main() {
    cout << "hellp" << endl;
    return 0;
}