#include <iostream>
#include <queue>

using namespace std;
template <typename T>
class BiTreeNode {
public:
    T data;
    BiTreeNode<T>* left;
    BiTreeNode<T>* right;

    BiTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BiTree {
public:

    // 递归前序遍历
    void preOrderTraversal(BiTreeNode<T>* node) {
        if (node) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    // 递归中序遍历
    void inOrderTraversal(BiTreeNode<T>* node) {
        if (node) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    // 递归后序遍历
    void postOrderTraversal(BiTreeNode<T>* node) {
        if (node) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    BiTree() : root(nullptr) {}

    // 构造函数
    BiTree(T rootValue) {
        root = new BiTreeNode<T>(rootValue);
    }

    // 层序遍历
    void levelOrderTraversal() {
        if (!root)
            return;

        queue<BiTreeNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            BiTreeNode<T>* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }

    BiTreeNode<T>* root;
};

int main() {
    char a,b,c,d;
    cout<<"请输入二叉树的先序遍历序列，其中空节点用'#'表示："<<endl;
    cin>>a>>b>>c>>d;
    // 创建二叉树
    BiTree<char> tree(a);
    tree.root->left = new BiTreeNode<char>(b);
    tree.root->right = new BiTreeNode<char>(c);
    tree.root->right->left = new BiTreeNode<char>(d);

    // 验证遍历操作
    cout << "先序遍历: ";
    tree.preOrderTraversal(tree.root);
    cout << endl;

    cout << "中序遍历: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;

    cout << "后序遍历: ";
    tree.postOrderTraversal(tree.root);
    cout << endl;

    cout << "层序遍历: ";
    tree.levelOrderTraversal();
    cout << endl;

    return 0;
}
