#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int id;
    vector<Node*> neighbors;
    Node(int id) : id(id) {}
};

void addEdge(Node* u, Node* v) {
    u->neighbors.push_back(v);
    v->neighbors.push_back(u);
}

bool dfs(Node* start, Node* end, vector<bool>& visited) {
    if (start == end) return true;
    visited[start->id] = true;
    for (Node* neighbor : start->neighbors) {
        if (!visited[neighbor->id]) {
            if (dfs(neighbor, end, visited)) return true;
        }
    }
    return false;
}

int main() {
    Node* farmer = new Node(0);
    Node* wolf = new Node(1);
    Node* sheep = new Node(2);
    Node* cabbage = new Node(3);

    addEdge(farmer, wolf);
    addEdge(farmer, sheep);
    addEdge(farmer, cabbage);

    vector<bool> visited(4, false);
    if (dfs(farmer, cabbage, visited)) {
        cout << "可以运过河" << endl;
    } else {
        cout << "不能运过河" << endl;
    }

    return 0;
}
