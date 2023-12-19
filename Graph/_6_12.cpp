#include<bits/stdc++.h>
using namespace std;
int mp[105][105];//定义图 
int n,m;//节点和边 
#define inf 88888888
int dis[105];//记录距离其他点到这个点的最大距离 
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mp[i][j]>mp[i][k]+mp[k][j]&&k!=i&&k!=j&&i!=j)
                    mp[i][j]=mp[i][k]+mp[k][j];
                //floyd算法求任意两点间的最短路径
                //通俗解释：如果i经过k到j比i直接到j要短，那么就更新最短路径
                //如果二者不连通，则距离依旧是inf
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mp[i][j]=inf;//初始值全赋值为最大
        }
    }

    for(int i=1;i<=m;i++)
    {
        int x;
        int y;
        int d;
        scanf("%d %d %d",&x,&y,&d);
        mp[x][y]=d;
        mp[y][x]=d;//由题意得是无向图，给图赋值
    }

    floyd();//计算任意两点最短路径
    memset(dis,0,sizeof(dis));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dis[i]<mp[i][j]&&i!=j)dis[i]=mp[i][j];
            //计算已经计算出任意两点最短路径时，另外的点到i点的最大距离
            //即需要用到的符合条件的魔法最大长度，如果有不连通的情况，那么就会被赋值inf，表示不连通
            //如果存在不连通的情况，那么所有的dis都会是inf
        }
    }

    int mm = inf;
    int from;
    for(int i=1;i<=n;i++)
    {
        if(mm>dis[i])
        {
            mm=dis[i];//遍历所有合法魔法长度，取出最小值 
            from = i;//记录合法的魔法起点 
        }
    }
    if(mm==inf)cout<<"0";//如果不连通
    else cout<<from<<" "<<mm;

    return 0;
} 

