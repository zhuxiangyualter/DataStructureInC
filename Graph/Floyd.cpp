/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-09.
*/
#include<bits/stdc++.h>
using namespace std;
//Floyd算法\
//Floyd算法是一种动态规划算法，其思想是：
//设G=(V,E)是一个带权有向图，其邻接矩阵为W，
//对于顶点i和j，从i到j的最短路径不外乎两种可能：
//1.直接从i到j；
//2.从i经过若干个顶点k到达j。
//所以，设d[i][j]为顶点i到顶点j的最短路径的权值和，则其递推关系式为：
//d[i][j]=min{d[i][j],d[i][k]+d[k][j]}
//Floyd算法的时间复杂度为O(n^3)，空间复杂度为O(n^2)。
//Floyd算法求解的是任意两点之间的最短路径，而Dijkstra算法是求解单源最短路径问题。
//Floyd算法可以解决带负权边的最短路径问题，但是不能解决带有负权回路的图的最短路径问题。
class Floyd{
public:
    int n;
    int **G;
    int **D;
    int **P;
    void createGraph(int n,int **G);
    void floyd();
    void printPath(int i,int j);

};
void Floyd::createGraph(int n,int **G){
    this->n=n;
    this->G=G;
    D=new int*[n];
    P=new int*[n];
    for(int i=0;i<n;i++){
        D[i]=new int[n];
        P[i]=new int[n];
        for(int j=0;j<n;j++){
            D[i][j]=G[i][j];
            P[i][j]=-1;
        }
    }
}
void Floyd::floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(D[i][k]+D[k][j]<D[i][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=k;
                }
            }
        }
    }
}
void Floyd::printPath(int i,int j){
    if(P[i][j]==-1){
        cout<<i<<" ";
        return;
    }
    printPath(i,P[i][j]);
    printPath(P[i][j],j);
}
int main(){
    int n;
    cin>>n;
    int **G=new int*[n];
    for(int i=0;i<n;i++){
        G[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>G[i][j];
        }
    }
    Floyd floyd;
    floyd.createGraph(n,G);
    floyd.floyd();
    floyd.printPath(0,5);
    return 0;
}
