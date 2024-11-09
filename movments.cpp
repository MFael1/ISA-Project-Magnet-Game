#include <bits/stdc++.h>
#include "utils.cpp"
using namespace std;
void repel(int x, int y, vector<vector<int>> &v);
void attract(int x, int y, vector<vector<int>> &v);
bool move(int x1, int y1, int x2, int y2, vector<vector<int>> &v)
{
    if (!isMovable(v[x1][y1]) || !isValidPos(x2, y2, v[x2][y2]))
        return 0;
    if (v[x2][y2])
    {
        if (v[x1][y1] < 10)
        {
            v[x2][y2] = 10 + v[x1][y1];
            v[x1][y1] = 0;
        }
        else
        {
            int temp = v[x1][y1] - 10;
            v[x1][y1] = 1;
            v[x2][y2] = 10 + temp;
        }
    }
    else
    {
        if (v[x1][y1] < 10)
        {
            v[x2][y2] = v[x1][y1];
            v[x1][y1] = 0;
        }
        else
        {
            v[x2][y2] = v[x1][y1];
            v[x1][y1] = 1;
        }
    }
    if (v[x2][y2] % 10 == 3)
    {
        repel(x2, y2, v);
    }
    else
    {
        attract(x2, y2, v);
    }
    return 1;
}

void repel(int x, int y, vector<vector<int>> &v)
{
    int x1, x2;
    // vertical Up
    for (int i = x - 1; i > 0; --i)
    {
        if (v[i][y] > 1)
        {
            x1 = i;

            while (i > 0 && v[i][y] > 1)
            {
                --i;
            }
            if (!isValidPos(i, y))
                break;
            x2 = i;
            for (int j = x2; j < x1; ++j)
            {
                replace(v[j + 1][y], v[j][y]);
            }
            break;
        }
    }
    // vertical Down
    for (int i = x + 1; i < v.size(); ++i)
    {
        if (v[i][y] > 1)
        {
            x1 = i;

            while (i < 5 && v[i][y] > 1)
            {
                ++i;
            }
            if (!isValidPos(i, y))
                break;
            x2 = i;
            for (int j = x2; j > x1; --j)
            {
                replace(v[j - 1][y], v[j][y]);
            }
            break;
        }
    }
    int y1, y2;
    // Horizental Right
    for (int i = y + 1; i < v[0].size(); ++i)
    {
        if (v[x][i] > 1)
        {
            y1 = i;
            while (i < 5 && v[x][i] > 1)
            {
                ++i;
            }
            if (!isValidPos(x, i))
                break;
            y2 = i;
            for (int j = y2; j > y1; --j)
            {
                replace(v[x][j - 1], v[x][j]);
            }
            break;
        }
    }
    // Horizental Left
    for (int i = y - 1; i > 0; --i)
    {
        if (v[x][i] > 1)
        {
            y1 = i;

            while (i > 0 && v[x][i] > 1)
            {
                --i;
            }
            if (!isValidPos(x, i))
                break;
            y2 = i;
            for (int j = y2; j < y1; ++j)
            {
                replace(v[x][j + 1], v[x][j]);
            }
            break;
        }
    }
}

void attract(int x, int y, vector<vector<int>> &v)
{
    int x1, x2;
    // vertical Up
    for (int i = x - 1; i >= 0; --i)
    {
        if (v[i + 1][y] < 2 && v[i][y] > 1)
            replace(v[i][y], v[i + 1][y]);
    }
    // vertical Down
    for (int i = x + 1; i < v.size(); ++i)
    {
        if (v[i - 1][y] < 2 && v[i][y] > 1)
            replace(v[i][y], v[i - 1][y]);
    }
    // horizental Right
    for (int i = y + 1; i < v[0].size(); ++i)
    {
        if (v[x][i - 1] < 2 && v[x][i] > 1)
            replace(v[x][i], v[x][i - 1]);
    }
    // horizental Left
    for (int i = y - 1; i >= 0; --i)
    {
        if (v[x][i + 1] < 2 && v[x][i] > 1)
            replace(v[x][i], v[x][i + 1]);
    }
}