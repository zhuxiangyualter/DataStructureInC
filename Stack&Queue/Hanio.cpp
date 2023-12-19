/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-08.
 * 递归解决汉诺塔问题,盘子的数量n=3,4,5
*/
#include<bits/stdc++.h>
using namespace std;
class Hanio{
public:
    void move(int n,char a,char b,char c){
        if (n==1) cout<<a<<"->"<<c<<endl;
        else{
            move(n-1,a,c,b);
            cout<<a<<"->"<<c<<endl;
            move(n-1,b,a,c);
        }
    }

};
int main() {
    Hanio hanio;
    int n1,n2,n3;
    cin>>n1;
    cout<<"请输入A塔上金碟的个数："<<n1;
    hanio.move(n1,'A','B','C');
    cin>>n2;
    cout<<"请输入A塔上金碟的个数："<<n2;
    hanio.move(n2,'A','B','C');
    cin>>n3;
    cout<<"请输入A塔上金碟的个数："<<n3;
    hanio.move(n3,'A','B','C');
    return 0;
}