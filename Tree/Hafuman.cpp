/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-09.
*/
//使用三叉链表的静态链表模板存储二叉树的各个结点，实现哈夫曼算法。
#include <iostream>
#include <queue>
#include <vector>
class Node {
public:
    int weight;
    int parent;
    int lchild;
    int rchild;

};
using namespace std;
class HuffmanTree {
public:
    vector<Node> tree;
    int n;
    void createTree(int *weight, int n);
    void printTree();
};
void HuffmanTree::createTree(int *weight, int n) {
    this->n = n;
    tree.resize(2 * n - 1);
    for (int i = 0; i < n; ++i) {
        tree[i].weight = weight[i];
        tree[i].parent = -1;
        tree[i].lchild = -1;
        tree[i].rchild = -1;
    }
    for (int i = n; i < 2 * n - 1; ++i) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int x1 = -1, x2 = -1;
        for (int j = 0; j < i; ++j) {
            if (tree[j].parent == -1) {
                if (tree[j].weight < min1) {
                    min2 = min1;
                    x2 = x1;
                    min1 = tree[j].weight;
                    x1 = j;
                } else if (tree[j].weight < min2) {
                    min2 = tree[j].weight;
                    x2 = j;
                }
            }
        }
        tree[x1].parent = i;
        tree[x2].parent = i;
        tree[i].lchild = x1;
        tree[i].rchild = x2;
        tree[i].weight = tree[x1].weight + tree[x2].weight;
    }
}
void HuffmanTree::printTree() {
    for (int i = 0; i < 2 * n - 1; ++i) {
        cout << "weight: " << tree[i].weight << " parent: " << tree[i].parent << " lchild: " << tree[i].lchild
             << " rchild: " << tree[i].rchild << endl;
    }
}
int main() {
    int weight[] = {5, 29, 7, 8, 14, 23, 3, 11};
    HuffmanTree huffmanTree;
    huffmanTree.createTree(weight, 8);
    huffmanTree.printTree();
    return 0;
}
