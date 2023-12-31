/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-10.
*/
#include<bits/stdc++.h>
using namespace std;
string name = "渚相玉";
//KMP算法
void GetNext(string t,int next[]){
    int i = 0,j = -1;
    next[0] = -1;
    while (i<t.length()){
        if (j==-1||t[i]==t[j]){
            i++;
            j++;
            next[i] = j;
        } else j = next[j];
    }
}
int KMP(string s,string t){
    int i = 0,j = 0;
    int next[100];
    GetNext(t,next);
    while (i<s.length()&&j<t.length()){
        if (j==-1||s[i]==t[j]){
            i++;
            j++;
        } else j = next[j];
    }
    if (j>=t.length()) return i-t.length();
    else return -1;
}
int main() {
    string s,t;
    cout<<"请输入主串："<<endl;
    cin>>s;
    cout<<"请输入子串："<<endl;
    cin>>t;
    cout<<"子串在主串中的位置为：";
    cout<<KMP(s,t);
    cout<<name;
    return 0;
}