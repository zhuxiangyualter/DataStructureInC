/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-18.
*/
#include<bits/stdc++.h>
using namespace std;
//七巧板涂色问题
class Seven {
private:
    /**
     * @param n 顶点数
     * @param m 边数
     * @param map 邻接矩阵
     * @param color 颜色
     * @param stack 栈
     * @param top 栈顶
     */
    int n, m;
    int **map;
    int *color;
    int *stack;
    int top;
public:
    //构造函数
    Seven(int n, int m) {
        this->n = n;
        this->m = m;
        map = new int*[n];
        for (int i = 0; i < n; i++) {
            map[i] = new int[n];
        }
        color = new int[n];
        stack = new int[n];
    }
    //初始化
    void init() {
        for (int i = 0; i < n; i++) {
            color[i] = 0;
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
    //着色
    void colorGraph() {
        int k = 0;
        stack[++top] = 0;
        color[0] = 1;
        while (top != 0) {
            int j = stack[top];
            int i;
            for (i = 0; i < n; i++) {
                if (map[j][i] == 1 && color[i] == 0) {
                    break;
                }
            }
            if (i == n) {
                top--;
            } else {
                stack[++top] = i;
                color[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                cout << "不是连通图" << endl;
                return;
            }
        }
        cout << "是连通图" << endl;
    }
    //析构函数
    ~Seven() {
        delete[] color;
        delete[] stack;
        for (int i = 0; i < n; i++) {
            delete[] map[i];
        }
        delete[] map;
    }
    //拷贝构造函数
    Seven(const Seven& seven) {
        n = seven.n;
        m = seven.m;
        map = new int*[n];
        for (int i = 0; i < n; i++) {
            map[i] = new int[n];
        }
        color = new int[n];
        stack = new int[n];
        for (int i = 0; i < n; i++) {
            color[i] = seven.color[i];
            stack[i] = seven.stack[i];
            for (int j = 0; j < n; j++) {
                map[i][j] = seven.map[i][j];
            }
        }
    }

};
int main() {
    //不要我输入  请给定数据

    int n, m;
    cout << "请输入顶点数和边数：";
    cin >> n >> m;
    Seven seven(n, m);
    seven.init();
    cout << "请输入边的连接关系（用空格隔开）：" << endl;
    seven.input();
    seven.colorGraph();

    return 0;
}