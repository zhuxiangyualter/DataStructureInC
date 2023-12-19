/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-30.
*/

#include <iostream>
#include <vector>
using namespace std;
#define max(N1,N2) N1>N2?N1:N2
int main()
{
    /*
    第一行输入背包容量V和物体的个数n
    接下来有n行，每行包含两个数字，分别为该物体的花费和价值
    */
    vector<int> w, v;//w为花费，v为价值
    vector<vector<int>> f;//f状态矩阵
    int V, n;//V背包容量，n物体数
    while (cin >> V >> n)
    {
        w.clear();
        v.clear();
        f.clear();
        w.push_back(0);
        v.push_back(0);

        //输入原始数据
        for (int i = 1; i <= n; i++)
        {
            int cur_w, cur_v;
            cin >> cur_w >> cur_v;
            w.push_back(cur_w);
            v.push_back(cur_v);
        }

        //初始化状态矩阵
        for (int i = 0; i <= n; i++)
        {
            vector<int> buff(V + 1, 0);
            f.push_back(buff);
        }

        //动态规划过程
        for (int i = 1; i <= n; i++)
        {
            for (int j = V; j >= 0; j--)
            {
                if (j >= w[i])
                {
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
                }
                else
                {
                    f[i][j] = f[i - 1][j];
                }
            }
        }

        //输出答案
        int ans = f[n][V];
        cout << ans << endl;
    }
    return 0;
}
