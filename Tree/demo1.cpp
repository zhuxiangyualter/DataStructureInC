#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// 计算二叉树的高度
int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// 计算二叉树中最大的结点距离
int diameter(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    // 情况1：直径经过根节点
    int throughRoot = height(root->left) + height(root->right) + 1;

    // 情况2：直径在左子树中
    int leftDiameter = diameter(root->left);

    // 情况3：直径在右子树中
    int rightDiameter = diameter(root->right);

    // 返回最大的距离
    return max(throughRoot, max(leftDiameter, rightDiameter));
}


int main() {
    // 构建一个二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // 计算最大结点距离（树的直径）
    int maxDistance = diameter(root);

    cout << "最大节点距离是: " << maxDistance << endl;


    return 0;
}

