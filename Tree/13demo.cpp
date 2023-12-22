#include <iostream>
#include <queue>

using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// 打印二叉树第 k 层的所有节点
void printKLevelNodes(TreeNode* root, int k) {
    if (root == nullptr || k <= 0) {
        cout << "Invalid input." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    int currentLevel = 1;

    while (!q.empty() && currentLevel <= k) {
        int levelSize = q.size();

        if (currentLevel == k) {
            cout << "Level " << currentLevel << ": ";
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                cout << node->val << " ";
            }
            cout << endl;
        } else {
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        currentLevel++;
    }

    if (currentLevel <= k) {
        cout << "Level " << k << " does not exist in the binary tree." << endl;
    }
}

// 打印二叉树第 k 层的叶子节点
void printKLevelLeaves(TreeNode* root, int k) {
    if (root == nullptr || k <= 0) {
        cout << "Invalid input." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    int currentLevel = 1;

    while (!q.empty() && currentLevel <= k) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if (currentLevel == k && node->left == nullptr && node->right == nullptr) {
                cout << "Leaf Node: " << node->val << endl;
            }

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }

        currentLevel++;
    }

    if (currentLevel <= k) {
        cout << "Level " << k << "不存在." << endl;
    }
}



int main() {
    // 构建一个二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 打印第 k 层的所有节点
    int k;
    cout << "输入要打印节点的层: ";
    cin >> k;

    printKLevelNodes(root, k);

    // 打印第 k 层的叶子节点
    cout << "输入要打印叶子节点的层: ";
    cin >> k;

    printKLevelLeaves(root, k);

    return 0;
}

