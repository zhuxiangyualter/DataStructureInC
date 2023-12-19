#include <iostream>

using namespace std;

struct Node
{
    char name[8];
    int color;
};
int main()
{
    int cnt_color = 1;
    int i, j;
    Node v[13] = {
            {"ED",0}, {"AC",0}, {"AD",0}, {"BA",0}, {"BC",0},
            {"BD",0}, {"DA",0}, {"DB",0}, {"DC",0}, {"EA",0},
            { "EB",0},{"EC",0},{ "AB", 0}
    };
    bool e[13][13] = {
            {0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,1,1,1,0,0,1,1,0},
            {0,0,0,0,0,1,0,0,0,1,1,1,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,1,0,0,1,1,1},
            {0,1,1,0,0,0,1,0,0,0,1,1,1},
            {0,1,0,0,1,1,0,0,0,0,1,1,1},
            {0,1,0,0,1,0,0,0,0,0,0,1,1},
            {0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,1,0,0,0,0,0,0,0,0,0,1},
            {0,1,1,0,1,1,1,0,0,0,0,0,1},
            {0,1,1,0,1,1,1,1,0,0,0,0,1},
            {0,0,0,0,1,1,1,1,0,1,1,1,0}
    };
    int result[13] = { 0 };
    for (i = 0; i < 13; i++)
    {
        if (v[i].color == 0)//未被涂色
        {
            bool flag = true;
            v[i].color = cnt_color;
            printf("第%d种颜色节点:%5s", cnt_color,v[i].name);
            for (j = 1; j < 13; j++)
                if (e[i][j] == 0 && v[j].color == 0)
                {
                    for (int k = 0; k < 13; k++)
                    {
                        if (v[k].color == v[i].color &&
                            e[j][k] == 1)//j与和i相同颜色的点相邻
                        {
                            flag = false;
                        }
                    }
                    if (flag)
                    {
                        v[j].color = cnt_color;
                        printf("%5s", v[j].name);
                    }
                }
            cnt_color++;
            printf("\n");
        }
    }
    printf("颜色总数: %d\n", cnt_color - 1);
    for (auto x : v)
    {
        printf("%s\t", x.name);
    }
    printf("\n");
    for (auto x : v)
    {
        printf("%d\t", x.color);
    }
}
