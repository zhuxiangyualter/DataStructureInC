#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 定义边的结构体
struct Edge {
    int to, cost;
    Edge(int t, int c) : to(t), cost(c) {}
};

// 定义优先队列中元素的比较函数
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

// Dijkstra算法实现
vector<int> dijkstra(const vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // 初始化距离数组
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // 初始化优先队列

    dist[start] = 0; // 源点到自身的距离为0
    pq.push({start, 0}); // 将源点加入优先队列

    while (!pq.empty()) {
        int u = pq.top().first; // 取出当前距离最短的顶点
        pq.pop();

        if (dist[u] < pq.top().second) continue; // 如果当前顶点的距离已经被更新过，跳过

        for (const Edge& e : graph[u]) {
            int v = e.to; // 邻接顶点
            int w = e.cost; // 边的权重
            if (dist[u] + w < dist[v]) { // 如果通过当前顶点到达邻接顶点的距离更短
                dist[v] = dist[u] + w; // 更新邻接顶点的距离
                pq.push({v, dist[v]}); // 将邻接顶点加入优先队列
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cin >> V >> E; // 输入顶点数和边数

    vector<vector<Edge>> graph(V); // 初始化图
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // 输入边的起点、终点和权重
        graph[u].push_back(Edge(v, w)); // 添加边到图中
    }

    int V0;
    cin >> V0; // 输入源点

    vector<int> dist = dijkstra(graph, V0); // 调用Dijkstra算法求最短路径长度

    for (int i = 0; i < V; ++i) {
        cout << "从顶点" << V0 << "到顶点" << i << "的最短路径长度为：" << dist[i] << endl;
    }

    return 0;
}
