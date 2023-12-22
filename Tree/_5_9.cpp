#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
template <typename T>
struct TreeNode {
    T data;
    int weight;
    int parent, left, right;
};

template <typename T>
class HuffmanTree {
private:
    vector<TreeNode<T>> nodes;

    // 选择权值最小的两个结点
    void selectMin(int n, int &s1, int &s2) {
        for (int i = 0; i < n; ++i) {
            if (nodes[i].parent == -1) {
                s1 = i;
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nodes[i].parent == -1 && nodes[i].weight < nodes[s1].weight) {
                s1 = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nodes[i].parent == -1 && i != s1) {
                s2 = i;
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nodes[i].parent == -1 && i != s1 && nodes[i].weight < nodes[s2].weight) {
                s2 = i;
            }
        }
    }

    // 构建哈夫曼树
    void buildHuffmanTree(int n) {
        if (n <= 1)
            return;

        for (int i = 0; i < n - 1; ++i) {
            int s1, s2;
            selectMin(n + i, s1, s2);
            nodes[s1].parent = nodes[s2].parent = n + i;

            nodes[n + i].left = s1;
            nodes[n + i].right = s2;
            nodes[n + i].weight = nodes[s1].weight + nodes[s2].weight;
        }
    }

    // 递归计算哈夫曼编码
    void generateHuffmanCode(int root, vector<string> &codes, string code) {
        if (root != -1) {
            if (nodes[root].left == -1 && nodes[root].right == -1) {
                codes[root] = code;
            }
            generateHuffmanCode(nodes[root].left, codes, code + '0');
            generateHuffmanCode(nodes[root].right, codes, code + '1');
        }
    }

public:
    HuffmanTree(vector<T> data, vector<int> weights) {
        int n = data.size();
        nodes.resize(2 * n - 1);

        for (int i = 0; i < n; ++i) {
            nodes[i].data = data[i];
            nodes[i].weight = weights[i];
            nodes[i].parent = nodes[i].left = nodes[i].right = -1;
        }

        buildHuffmanTree(n);
    }

    // 打印哈夫曼编码
    void printHuffmanCodes() {
        vector<string> codes(nodes.size());
        generateHuffmanCode(nodes.size() - 1, codes, "");

        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i].left == -1 && nodes[i].right == -1) {
                cout << "Character: " << nodes[i].data << ", Code: " << codes[i] << endl;
            }
        }
    }
};

int main() {
    vector<char> data = {'A', 'B', 'C', 'D'};
    vector<int> weights = {2, 5, 8, 12};

    HuffmanTree<char> huffmanTree(data, weights);
    huffmanTree.printHuffmanCodes();

    return 0;
}
