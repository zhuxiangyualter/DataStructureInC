/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-09.
*/
//prime算法
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Graph {
public:
    int n;
    vector<vector<int>> edges;
    vector<int> visited;
    void createGraph(int n);
    void addEdge(int u, int v, int w);
    void printGraph();
    void prim();
};
void Graph::createGraph(int n) {
    this->n = n;
    edges.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; ++i) {
        edges[i].resize(n);
        visited[i] = 0;
    }
}
void Graph::addEdge(int u, int v, int w) {
    edges[u][v] = w;
    edges[v][u] = w;
}
void Graph::printGraph() {
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int j = 0; j < n; ++j) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}
void Graph::prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    int ans = 0;
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        if (visited[u]) continue;
        visited[u] = 1;
        ans += p.first;
        for (int i = 0; i < n; ++i) {
            if (edges[u][i] && !visited[i]) {
                pq.push(make_pair(edges[u][i], i));
            }
        }
    }
    cout << ans << endl;
}
int main() {
    int n, m;
    cout << "请输入顶点数和边数：";
    cin >> n >> m;
    Graph graph;
    graph.createGraph(n);
    cout << "请输入边的连接关系（用空格隔开）：" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    graph.printGraph();
    graph.prim();
    return 0;
}