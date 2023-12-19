/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-26.
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 35
map<int,int>indexMap;
int pos = 0;
int n = 0;
int post [MAX];
int  in[MAX];
int  pre[MAX];
void build(int il,int ir,int pl,int pr){
    if(il>ir)
        return;
    int root = post[pr];
    pre[pos++] = root;
    auto k = indexMap.find(root);
    int K = k->first;
    int len = K -il;
    build(il,K-1,pl,pl+len-1);
    build(K+1,ir,pl+len,pr-1);

}

int main() {



    return 0;
}