#include <bits/stdc++.h>
using namespace std;
const string WHITE = "\033[37mO\033[0m";
const string GRAY = "\033[90mO\033[0m";
const string RED = "\033[91mO\033[0m";
const string PURPLE = "\033[95mO\033[0m";
const string SRED = "\033[91m@\033[0m";
const string SPURPLE = "\033[95m@\033[0m";
const string EMPTY = ".";
void resetColor()
{
    cout << "\033[0m";
}

void setColor(const string &color)
{
    if (color == "red")
    {
        cout << "\033[31m";
    }
    else if (color == "green")
    {
        cout << "\033[32m";
    }
    else if (color == "blue")
    {
        cout << "\033[34m";
    }
    else if (color == "yellow")
    {
        cout << "\033[33m";
    }
}
string shifting(int w = 40)
{
    return string(w, ' ');
}
void display(vector<vector<int>> &v)
{
    int width = v.size();
    int shift = 40;

    cout << "\n\n";
    cout << shifting() << "  1  " << " 2  " << " 3  " << " 4  " << " 5  " << "\n";
    cout << shifting() << string(width * 4, '-') << "\n";
    int num = 1;
    for (const auto &row : v)
    {
        cout << shifting(37) << num++ << " ";

        for (const auto &cell : row)
        {
            switch (cell)
            {
            case 1:
                cout << "| " << WHITE << " ";
                break;
            case 2:
                cout << "| " << GRAY << " ";
                break;
            case 3:
                cout << "| " << PURPLE << " ";
                break;
            case 4:
                cout << "| " << RED << " ";
                break;
            case 13:
                cout << "| " << SPURPLE << " ";
                break;
            case 14:
                cout << "| " << SRED << " ";
                break;
            default:
                cout << "| " << EMPTY << " ";
                break;
            }
        }
        cout << "|\n";
        cout << shifting() << string(width * 4, '-') << "\n";
    }
    cout << "\n";
}

void displayByNumbers(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[0].size(); ++j)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool isValidPos(int x, int y, int val = 0)
{
    return x < 5 && x >= 0 && y < 5 && y >= 0 && val < 2;
}

bool isMovable(int val)
{
    return val > 2;
}

bool isSolved(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[0].size(); ++j)
        {
            if (v[i][j] == 1)
                return 0;
        }
    }
    return 1;
}

void replace(int &x, int &y)
{
    if (x < 10)
    {
        if (y)
        {
            y = 10 + x;
            x = 0;
        }
        else
        {
            swap(x, y);
        }
    }
    else
    {
        if (y)
        {
            swap(x, y);
        }
        else
        {
            y = x - 10;
            x = 1;
        }
    }
}
