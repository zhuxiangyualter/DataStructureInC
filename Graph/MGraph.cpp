#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//图这一章全部需要输入，图的类型包括：有向图，无向图，有向网，无向网，根据具体情况决定。
//图需要输入图的顶点个数，边数，边依附的顶点以及可能的权值。
template <typename T>
class MGraph {
public:
    MGraph(int n) : adjMatrix(n, vector<T>(n, 0)) {}

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void DFS(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (int i = 0; i < adjMatrix.size(); ++i) {
            if (adjMatrix[u][i] && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    void BFS(int u) {
        vector<bool> visited(adjMatrix.size(), false);
        queue<int> q;

        visited[u] = true;
        q.push(u);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int i = 0; i < adjMatrix.size(); ++i) {
                if (adjMatrix[u][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

private:
    vector<vector<T>> adjMatrix;
};

int main() {
    int n, m;
    cout << "请输入顶点数和边数：";
    cin >> n >> m;

    MGraph<int> graph(n);
    cout << "请输入边的连接关系（用空格隔开）：" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "深度优先遍历结果：" << endl;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            graph.DFS(i, visited);
        }
    }
    cout << endl;

    cout << "广度优先遍历结果：" << endl;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            graph.BFS(i);
        }
    }
    cout << endl;

    return 0;
}
