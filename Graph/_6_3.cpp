#include <iostream>
using namespace std;

const int MaxSize = 10;                   //图中最多顶点个数
int visited[MaxSize] = {0};              //全局数组变量visited初始化
template <class DataType>
class MGraph
{
public:
    MGraph(DataType a[ ], int n, int e);     //构造函数，建立具有n个顶点e条边的图
    void Prim(int v);
private:
    DataType vertex[MaxSize];           //存放图中顶点的数组
    int edge[MaxSize][MaxSize];           //存放图中边的数组
    int vertexNum, edgeNum;              //图的顶点数和边数

    int MinEdge(int r[ ], int n);
};

template <class DataType>
MGraph<DataType> :: MGraph(DataType a[ ], int n, int e)
{
    int i, j, k, w;
    vertexNum = n; edgeNum = e;
    for (i = 0; i < vertexNum; i++)          //存储顶点
        vertex[i] = a[i];
    for (i = 0; i < vertexNum; i++)          //初始化邻接矩阵
        for (j = 0; j < vertexNum; j++)
            if (i == j)
                edge[i][j] = 0;
            else
                edge[i][j] = 100;               //假设边上权的最大值是100
    for (k = 0; k < edgeNum; k++)           //依次输入每一条边
    {
        cout << "请输入边依附的两个顶点的编号，以及边上的权值：";
        cin >> i >> j >> w;                       //输入边依附的两个顶点的编号
        edge[i][j] = w; edge[j][i] = w;           //置有边标志
    }
}

template <class DataType>
void MGraph<DataType> :: Prim(int v)                           //从顶点v出发
{
    int i, j, k;
    int adjvex[MaxSize], lowcost[MaxSize];//存储邻接顶点和相应的权值
    for (i = 0; i < vertexNum; i++)             //初始化辅助数组
    {
        lowcost[i] = edge[v][i]; adjvex[i] = v;
    }
    lowcost[v] = 0;                         //// 将顶点 v 的权值设置为0，表示顶点 v 已经在最小生成树中
    for (k = 1; k < vertexNum; k++)            //迭代n-1次
    {
        j = MinEdge(lowcost, vertexNum);       //寻找最短边的邻接点j
        cout << "(" << vertex[j] << "," << vertex[adjvex[j]] << ")" << lowcost[j] << endl;
        lowcost[j] = 0;                       //顶点j加入集合U
        for (i = 0; i < vertexNum; i++)          //调整辅助数组
            if (edge[i][j] < lowcost[i]) {
                lowcost[i] = edge[i][j];
                adjvex[i] = j;
            }
    }
}

template <class DataType>
int MGraph<DataType> :: MinEdge(int r[ ], int n)
{
    int index = 0, min = 100;           //此处如果仅记载最小值下标会有bug
    for (int i = 1; i < n; i++)
        if (r[i] != 0 && r[i] < min)
        {
            min = r[i]; index = i;
        }
    return index;
}

int main() {
    int n, e;
    cout << "请输入图的顶点数和边数：";
    cin >> n >> e;

    int vertices[MaxSize];
    cout << "请输入图的顶点：";
    for (int i = 0; i < n; ++i) {
        cin >> vertices[i];
    }

    MGraph<int> graph(vertices, n, e);

    int startVertex;
    cout << "请输入开始构建最小生成树的顶点编号：";
    cin >> startVertex;

    cout << "最小生成树的边：" << endl;
    graph.Prim(startVertex);

    return 0;
}









