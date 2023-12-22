#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// ����������ĸ߶�
int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// ��������������Ľ�����
int diameter(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    // ���1��ֱ���������ڵ�
    int throughRoot = height(root->left) + height(root->right) + 1;

    // ���2��ֱ������������
    int leftDiameter = diameter(root->left);

    // ���3��ֱ������������
    int rightDiameter = diameter(root->right);

    // �������ľ���
    return max(throughRoot, max(leftDiameter, rightDiameter));
}


int main() {
    // ����һ��������
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // �����������루����ֱ����
    int maxDistance = diameter(root);

    cout << "���ڵ������: " << maxDistance << endl;


    return 0;
}

