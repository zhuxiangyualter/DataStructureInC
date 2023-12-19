/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-18.
*/
#include<bits/stdc++.h>
using namespace std;
class AOV {
private:
    /**
     * @param n 顶点数
     * @param m 边数
     * @param inDegree 入度
     * @param topo 拓扑序列
     * @param etv 事件最早发生时间
     * @param stack 栈
     * @param top 栈顶
     * @param e 事件最晚发生时间
     * @param map 邻接矩阵
     * @param ve 事件最早发生时间
     * @param vl 事件最晚发生时间
     */
    int n, m;
    int *inDegree;
    int *topo;
    int *etv;
    int *stack;
    int top;
    int *e;
    int **map;
    int *ve;
    int *vl;
public:
    //构造函数
    AOV(int n, int m) {
        this->n = n;
        this->m = m;
        inDegree = new int[n];//入度
        topo = new int[n];//拓扑序列
        etv = new int[n];//事件最早发生时间
        stack = new int[n];//栈
        e = new int[n];//事件最晚发生时间
        map = new int*[n];//邻接矩阵
        for (int i = 0; i < n; i++) {
            map[i] = new int[n];
        }
        ve = new int[n];//事件最早发生时间
        vl = new int[n];//事件最晚发生时间
    }
    //初始化
    void init() {
        for (int i = 0; i < n; i++) {
            inDegree[i] = 0;
            topo[i] = 0;
            etv[i] = 0;
            stack[i] = 0;
            e[i] = 0;
            ve[i] = 0;
            vl[i] = 0;
        }
        top = 0;
    }
    //输入
    void input() {
        int x, y, w;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> w;
            map[x][y] = w;
            inDegree[y]++;
        }
    }
    //拓扑排序
    void topoSort() {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                stack[++top] = i;
            }
        }
        while (top != 0) {
            int j = stack[top--];
            topo[++k] = j;//拓扑序列
            for (int i = 0; i < n; i++) {
                if (map[j][i] != 0) {
                    inDegree[i]--;
                    if (inDegree[i] == 0) {
                        stack[++top] = i;
                    }//入度为0入栈
                    if (ve[j] + map[j][i] > ve[i]) {
                        ve[i] = ve[j] + map[j][i];
                    }//计算事件最早发生时间
                }
            }
        }
        if (k < n) {
            cout << "有回路" << endl;
        }//有回路
    }
    //打印
    void print() {
        for (int i = 0; i < n; i++) {
            cout << ve[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << vl[i] << " ";
        }
        cout << endl;
    }
    //析构函数
    ~AOV() {
        delete[] inDegree;
        delete[] topo;
        delete[] etv;
        delete[] stack;
        delete[] e;
        for (int i = 0; i < n; i++) {
            delete[] map[i];
        }
        delete[] map;
        delete[] ve;
        delete[] vl;
    }

};
int main() {
    int n=0, m=0;
    cout << "请输入顶点数和边数：";
    cin >> n >> m;
    AOV aov(n, m);
    aov.init();
    aov.input();
    aov.topoSort();
    aov.print();

    return 0;
}