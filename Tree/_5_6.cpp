#include <iostream>
using namespace std;

// 二叉树节点的模板类
template <class T>
class BiTreeNode {
public:
    T data;
    BiTreeNode<T>* leftChild, * rightChild;
    BiTreeNode() :leftChild(nullptr), rightChild(nullptr) {}
    BiTreeNode(T item, BiTreeNode<T>* left = nullptr, BiTreeNode<T>* right = nullptr)
            :data(item), leftChild(left), rightChild(right) {}
};

// 二叉树的类模板
template <class T>
class BiTree {
public:
    BiTreeNode<T>* root;
    BiTree() :root(nullptr) {}
    void CreateBiTree(BiTreeNode<T>*& R) {//使用先序遍历创建二叉树
        T item;
        cin >> item;
        if (item == '#')    R = nullptr;
        else {
            R = new BiTreeNode<T>(item);
            CreateBiTree(R->leftChild);
            CreateBiTree(R->rightChild);
        }
    }

    bool isSymmetricHelper(BiTreeNode<T>* left, BiTreeNode<T>* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        return (left->data == right->data)
               && isSymmetricHelper(left->leftChild, right->rightChild)
               && isSymmetricHelper(left->rightChild, right->leftChild);
    }

    bool IsSymmetric() {
        if (root == nullptr) return true;
        return isSymmetricHelper(root->leftChild, root->rightChild);
    }

    void PrintResult() {
        bool isSymmetric = IsSymmetric();
        cout << "该二叉树是否是对称的：" << (isSymmetric ? "是" : "否") << endl;
    }
};

int main() {
    BiTree<char> tree1, tree2;

    cout << "请输入二叉树的先序遍历序列，其中空节点用'#'表示：" << endl;
    tree1.CreateBiTree(tree1.root);
    tree1.PrintResult();

    cout << "请输入另一个二叉树的先序遍历序列，其中空节点用'#'表示：" << endl;
    tree2.CreateBiTree(tree2.root);
    tree2.PrintResult();
    cout << "王观祥" << endl;
    return 0;
}