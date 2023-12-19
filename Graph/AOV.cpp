#include<bits/stdc++.h>
using namespace std;
//Aov网  不允许有回路
//
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
    //关键路径
    void criticalPath() {
        topoSort();//拓扑排序
        for (int i = 0; i < n; i++) {
            vl[i] = ve[n - 1];
        }//初始化事件最晚发生时间
        while (topo[top]!= n - 1) {
            int j = topo[top--];//逆拓扑序列
            for (int i = 0; i < n; i++) {
                if (map[j][i] != 0) {//逆拓扑序列
                    if (vl[i] - map[j][i] < vl[j])
                    {
                        vl[j] = vl[i] - map[j][i];//计算事件最晚发生时间
                    }
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (map[j][i] != 0) {//逆拓扑序列
                    int e = ve[j];//事件最早发生时间
                    int l = vl[i] - map[j][i];//事件最晚发生时间
                    if (e == l) {
                        cout << j << "->" << i << endl;
                    }//关键路径
                }
            }
        }
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
    //拷贝构造函数
    AOV(const AOV& aov) {
        n = aov.n;
        m = aov.m;
        inDegree = new int[n];
        topo = new int[n];
        etv = new int[n];
        stack = new int[n];
        e = new int[n];
        map = new int*[n];
        for (int i = 0; i < n; i++) {
            map[i] = new int[n];
        }
        ve = new int[n];
        vl = new int[n];
        for (int i = 0; i < n; i++) {
            inDegree[i] = aov.inDegree[i];
            topo[i] = aov.topo[i];
            etv[i] = aov.etv[i];
            stack[i] = aov.stack[i];
            e[i] = aov.e[i];
            ve[i] = aov.ve[i];
            vl[i] = aov.vl[i];
            for (int j = 0; j < n; j++) {
                map[i][j] = aov.map[i][j];
            }
        }
    }


};
//格尼斯堡七桥问题
class Euler {
private:
    /**
     * @param n 顶点数
     * @param m 边数
     * @param map 邻接矩阵
     * @param stack 栈
     * @param top 栈顶
     * @param path 路径
     */
    int n, m;
    int **map;
    int *stack;
    int top;
    int *path;
public:
    //构造函数
    Euler(int n, int m) {
        this->n = n;
        this->m = m;
        map = new int*[n];
        for (int i = 0; i < n; i++) {
            map[i] = new int[n];
        }
        stack = new int[n];
        path = new int[m + 1];
    }
    //初始化
    void init() {
        for (int i = 0; i < n; i++) {
            stack[i] = 0;
            for (int j = 0; j < n; j++) {
                map[i][j] = 0;
            }
        }
        top = 0;
    }
    //输入
    void input() {
        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            map[x][y] = 1;
            map[y][x] = 1;
        }
    }
    //欧拉回路
    void eulerCircuit() {
        int k = 0;
        stack[++top] = 0;
        while (top != 0) {
            int j = stack[top];
            int i;
            for (i = 0; i < n; i++) {
                if (map[j][i] == 1) {
                    break;
                }
            }
            if (i == n) {
                path[++k] = j;
                top--;
            } else {
                stack[++top] = i;
                map[j][i] = 0;
                map[i][j] = 0;
            }
        }
        for (int i = m; i > 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    //欧拉路径
    void eulerPath() {
        int k = 0;
        int count = 0;
        stack[++top] = 0;
        while (top != 0) {
            int j = stack[top];
            int i;
            for (i = 0; i < n; i++) {
                if (map[j][i] == 1) {
                    break;
                }
            }
            if (i == n) {
                path[++k] = j;
                top--;
            } else {
                stack[++top] = i;
                map[j][i] = 0;
                map[i][j] = 0;

            }
        }
        for (int i = m; i > 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < m; i++) {
            if (path[i] == 0) {
                count++;
            }
        }
        if (count == 2) {
            cout << "欧拉路径" << endl;
        } else {
            cout << "不是欧拉路径" << endl;
        }
    }
    //判断是否是欧拉回路
    bool isEulerCircuit() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += map[i][j];
            }
            if (sum % 2 == 1) {
                count++;
            }
        }
        if (count == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Euler euler(n, m);
    euler.init();
    euler.input();
    if (euler.isEulerCircuit()) {
        euler.eulerCircuit();
    } else {
        euler.eulerPath();
    }
    return 0;
}