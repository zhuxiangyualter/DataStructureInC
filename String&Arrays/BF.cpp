/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-10.
*/
#include<bits/stdc++.h>
using namespace std;
//BF算法
string name = "渚相玉";
int BF(string s,string t){
    int i = 0,j = 0;
    while (i<s.length()&&j<t.length()){
        if (s[i]==t[j]){
            i++;
            j++;
        } else{
            i = i-j+1;
            j = 0;
        }
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
    cout<<BF(s,t);
    cout<<name;
    return 0;
}