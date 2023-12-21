#include <iostream>
using namespace std;
template <class ElemType>
/*二叉树的结点结构*/
struct BiNode{
    ElemType data;
    BiNode<ElemType> *lchild, *rchild;
    int maxLeft; /*左子树结点的最大距离*/
    int maxRight; /*右子树结点的最大距离*/
};

template <class ElemType>
class BiTree{
public:
    /*构造函数，建立一棵二叉树*/
    BiTree() {
        root = Creat(root);
    }

    void GetMaxPathLength() {
        GetMaxPathLength(root);
    }
private:
    BiNode<ElemType> *root; /*指向根结点的头指针*/
    BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*构造函数调用*/
    void GetMaxPathLength(BiNode<ElemType> *bt); /*求二叉树的结点的最大距离*/
};

/*全局变量，记录二叉树的最大的结点距离*/
int maxLen = 0;
template <class ElemType>
BiNode<ElemType> *BiTree<ElemType>::Creat(BiNode<ElemType> *bt) {
    char ch;
    cout<<"请输入创建一棵二叉树的结点数据："<<endl;
    cin>>ch;
    /*'#'代表空二叉树*/
    if(ch == '#')
        return NULL;
    else {
        bt = new BiNode<ElemType>; /*生成新结点*/
        bt->data = ch;
        bt->lchild = Creat(bt->lchild); /*递归创建左子树*/
        bt->rchild = Creat(bt->rchild); /*递归创建右子树*/
    }
    return bt;
}

template <class ElemType>
void BiTree<ElemType>::GetMaxPathLength(BiNode<ElemType> *bt) {
    /*二叉树为空，空操作返回*/
    if(bt == NULL) {
        return;
    }
    /*二叉树左子树为空，则左子树的最大结点距离为0*/
    if(bt->lchild == NULL) {
        bt->maxLeft = 0;
    }
    /*二叉树右子树为空，则右子树的最大结点距离为0*/
    if(bt->rchild == NULL) {
        bt->maxRight = 0;
    }
    /*如果左子树不为空，递归寻找左子树的最大结点距离*/
    if(bt->lchild != NULL) {
        GetMaxPathLength(bt->lchild);
    }
    /*如果右子树不为空，递归寻找右子树的最大结点距离*/
    if(bt->rchild != NULL) {
        GetMaxPathLength(bt->rchild);
    }
    /*计算左子树最大结点距离*/
    if(bt->lchild != NULL) {
        int temp = 0;
        int ll = bt->lchild->maxLeft;
        int lr = bt->lchild->maxRight;
        temp = ll > lr ? ll : lr;
        bt->maxLeft = temp + 1;
    }
    /*计算右子树最大结点距离*/
    if(bt->rchild != NULL) {
        int temp = 0;
        int rl = bt->rchild->maxLeft;
        int rr = bt->rchild->maxRight;
        temp = rl > rr ? rl : rr;
        bt->maxRight = temp + 1;
    }
    /*更新最大结点距离*/
    if(bt->maxLeft + bt->maxRight > maxLen) {
        maxLen = bt->maxLeft + bt->maxRight;
    }
}
typedef struct BiTreeNode{
    int date;
    BiTreeNode *lchild;
    BiTreeNode *rchild;
}*BiTree;

struct Result{
    int maxDepth;//最大深度
    int maxDistance;//最大距离
};

//函数声明
int max(int ld,int rd);
Result GetMaxDistance(BiTreeNode *root);
void CreateBiTree(BiTree &root);

int main()
{
    BiTree root=NULL;
    CreateBiTree(root);
    cout<<"Input end!"<<endl;
    Result res;
    res=GetMaxDistance(root);
    cout<<"MaxDistance="<<max(res.maxDepth,res.maxDistance)<<endl;
}

Result GetMaxDistance(BiTreeNode *root)
{
    if(root==NULL)//递归结束
    {
        Result res={-1,0};//最大深度为-1，因为之后还要对其加1然后变为0
        return res;
    }
    Result ls=GetMaxDistance(root->lchild);//左子树
    Result rs=GetMaxDistance(root->rchild);//右子树
    Result res;
    res.maxDepth=max(ls.maxDepth,rs.maxDepth)+1;//左子树和右子树中最大深度加1
    //求最大距离，返回第一个参数表示最大距离经过根结点，返回第二个参数表示最大距离不经过根结点
    res.maxDistance=max(ls.maxDepth+rs.maxDepth+2,max(ls.maxDistance,rs.maxDistance));
    return res;
}

int max(int ld,int rd)//返回最大值
{
    return ld > rd ? ld: rd;
}

void CreateBiTree(BiTree &root)//先序创建一课二叉树
{
    char data;
    data=getchar();
    if(data=='#')//输入'#'表示为空，递归结束
        root=NULL;
    else
    {
        root=new BiTreeNode();//新建一个结点
        root->date=data;
        CreateBiTree(root->lchild);
        CreateBiTree(root->rchild);
    }
}