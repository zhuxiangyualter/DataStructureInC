#include <iostream>
using namespace std;

// 定义一个模板结构体，表示中序线索二叉树的节点
template <typename T>
struct InThrBiTree {
    T data; // 节点数据
    InThrBiTree *lchild, *rchild, *parent; // 左右子节点和父节点指针
    bool lthread, rthread; // 左右子节点是否为线索
};

// 定义一个模板类，用于中序遍历中序线索二叉树
template <typename T>
class InThrBiTreeTraversal {
public:
    // 中序遍历函数，参数为根节点指针
    static void inorder(InThrBiTree<T> *root) {
        if (root == nullptr || (!root->lthread && !root->rthread)) { // 如果节点为空或者左右子节点都不是线索，直接返回
            return;
        }
        if (root->lthread) { // 如果左子节点是线索，递归遍历左子树
            inorder(root->lchild);
        }
        cout << root->data << " "; // 输出当前节点数据
        if (root->rthread) { // 如果右子节点是线索，递归遍历右子树
            inorder(root->rchild);
        }
    }
};

// 定义一个模板函数，用于创建中序线索二叉树
template <typename T>
InThrBiTree<T> *createThreadedList(InThrBiTree<T> *root) {
    if (root == nullptr) { // 如果根节点为空，直接返回
        return nullptr;
    }
    if (root->lthread) { // 如果左子节点是线索，递归创建左子树的线索链表
        createThreadedList(root->lchild);
    } else { // 如果左子节点不是线索，找到左子树的最右节点，将其右子节点设置为当前节点的右子节点，并将当前节点插入到最右节点的右子节点中
        InThrBiTree<T> *pre = root;
        while (!pre->lthread) {
            pre = pre->parent;
        }
        if (pre->lchild != nullptr) {
            pre->lchild->rthread = false;
            pre->lchild->rchild = root->rchild;
            if (root->rchild != nullptr) {
                root->rchild->parent = pre->lchild;
            }
            root->parent = pre;
            root->lchild = pre->lchild;
            pre->lchild = root;
        }
    }
    if (root->rthread) { // 如果右子节点是线索，递归创建右子树的线索链表
        createThreadedList(root->rchild);
    } else { // 如果右子节点不是线索，找到右子树的最左节点，将其左子节点设置为当前节点的左子节点，并将当前节点插入到最左节点的左子节点中
        InThrBiTree<T> *post = root;
        while (!post->rthread) {
            post = post->parent;
        }
        if (post->rchild != nullptr) {
            post->rchild->lthread = false;
            post->rchild->lchild = root->lchild;
            if (root->lchild != nullptr) {
                root->lchild->parent = post->rchild;
            }
            root->parent = post;
            root->rchild = post->rchild;
            post->rchild = root;
        }
    }
    return root; // 返回创建好的线索链表的根节点指针
}

int main() {
    // 创建中序线索二叉树的示例代码，具体数据需要根据实际情况填写
    InThrBiTree<int> *root = new InThrBiTree<int>{10, nullptr, nullptr, nullptr, false, false};
    root->lchild = new InThrBiTree<int>{5, nullptr, nullptr, nullptr, false, false};
    root->rchild = new InThrBiTree<int>{15, nullptr, nullptr, nullptr, false, false};
    root->lchild->parent = root;
    root->rchild->parent = root;
    root->lthread = true;
    root->rthread = true;

    InThrBiTree<int> *threadedListRoot = createThreadedList(root); // 创建线索链表
    InThrBiTreeTraversal<int>::inorder(threadedListRoot); // 中序遍历线索链表并输出结果
    cout << endl;

    return 0;
}
