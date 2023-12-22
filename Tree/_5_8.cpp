#include <bits/stdc++.h>

using namespace std;
template <typename DataType>
class InThrBiTree;

template <typename DataType>
class BiThrNode {
    friend class InThrBiTree<DataType>;

public:
    BiThrNode(DataType value = 0) : data(value), lchild(nullptr), rchild(nullptr), LTag(Link), RTag(Link) {}
    DataType data;
    BiThrNode<DataType>* lchild;
    BiThrNode<DataType>* rchild;
    PointerTag LTag;
    PointerTag RTag;
};

template <typename DataType>
class InThrBiTree {
public:
    InThrBiTree() : root(nullptr), pre(nullptr) {}

    // 构造未线索化的中序线索二叉链表
    void CreateInThrBiTree(BiThrNode<DataType>*& node) {
        DataType ch;
        std::cin >> ch;
        if (ch == '#') {
            node = nullptr;
        } else {
            node = new BiThrNode<DataType>(ch);
            CreateInThrBiTree(node->lchild);
            if (pre != nullptr) {
                pre->rchild = node;
                pre->RTag = Thread;
            }
            pre = node;
            CreateInThrBiTree(node->rchild);
        }
    }

    // 构造中序线索二叉树
    void InOrderThreading() {
        root = new BiThrNode<DataType>();
        pre = root;
        if (root != nullptr) {
            InThreading(root);
            pre->rchild = root;
            pre->RTag = Thread;
            root->rchild = pre;
        }
    }

    // 输出中序线索二叉树的中序遍历序列
    void InOrderTraverse() const {
        BiThrNode<DataType>* p = root->lchild;
        while (p != root) {
            while (p->LTag == Link) {
                p = p->lchild;
            }
            std::cout << p->data << " ";
            while (p->RTag == Thread && p->rchild != root) {
                p = p->rchild;
                std::cout << p->data << " ";
            }
            p = p->rchild;
        }
        std::cout << std::endl;
    }

private:
    BiThrNode<DataType>* root;
    BiThrNode<DataType>* pre;

    // 中序遍历线索化
    void InThreading(BiThrNode<DataType>* node) {
        if (node != nullptr) {
            InThreading(node->lchild);

            if (node->lchild == nullptr) {
                node->LTag = Thread;
                node->lchild = pre;
            }

            if (pre->rchild == nullptr) {
                pre->RTag = Thread;
                pre->rchild = node;
            }

            pre = node;
            InThreading(node->rchild);
        }
    }
};

int main() {
    InThrBiTree<char> tree;
    std::cout << "请输入二叉树的前序遍历序列（#表示空节点）：" << std::endl;
    tree.CreateInThrBiTree(tree.root);
    tree.InOrderThreading();

    std::cout << "中序遍历序列：" << std::endl;
    tree.InOrderTraverse();

    return 0;
}
