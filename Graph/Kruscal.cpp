#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
public:
    int vertices;
    vector<Edge> edges;

    Graph(int v) : vertices(v) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    vector<Edge> kruskal() {
        vector<Edge> result;

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(vertices);
        vector<int> rank(vertices, 0);

        for (int i = 0; i < vertices; i++) {
            parent[i] = i;
        }

        int i = 0;
        int e = 0;

        while (e < vertices - 1) {
            Edge nextEdge = edges[i++];
            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);

            if (x != y) {
                result.push_back(nextEdge);
                Union(parent, rank, x, y);
                e++;
            }
        }

        return result;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    vector<Edge> minSpanningTree = g.kruskal();

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const Edge& edge : minSpanningTree) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
