#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 定义邻接表结构体
template <typename T>
struct ALGraph {
    int V; // 顶点数
    vector<vector<T>> adj; // 邻接表

    // 构造函数
    ALGraph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // 添加边
    void addEdge(int u, int v, T w) {
        adj[u].push_back({v, w});
    }

    // 深度优先遍历
    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            if (!visited[i->first]) {
                DFSUtil(i->first, visited);
            }
        }
    }

    // 广度优先遍历
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            cout << u << " ";
            q.pop();

            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                if (!visited[i->first]) {
                    visited[i->first] = true;
                    q.push(i->first);
                }
            }
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E; // 输入顶点数和边数

    ALGraph<int> graph(V); // 创建有向图对象

    // 输入边的信息
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    cout << "深度优先遍历结果：";
    graph.DFS(0); // 从顶点0开始深度优先遍历
    cout << endl;

    cout << "广度优先遍历结果：";
    graph.BFS(0); // 从顶点0开始广度优先遍历
    cout << endl;

    return 0;
}
