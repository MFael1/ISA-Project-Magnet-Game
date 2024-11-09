#include <iostream>
#include <vector>
#include "states.cpp"
#include "..\movments.cpp"
using namespace std;
vector<pair<int, int>> getValidMoves(int x, int y, const vector<vector<int>> &v)
{
    vector<pair<int, int>> moves;
    for (int i = 0; i < v.size(); ++i)
        for (int j = 0; j < v[0].size(); ++j)
            if (v[i][j] < 2)
                moves.push_back({i, j});
    return moves;
}

State applyMove(const State &state, int x1, int y1, int x2, int y2)
{
    State newState = state;
    move(x1, y1, x2, y2, newState.v);
    vector<int> arr = {x1, y1, x2, y2};
    newState.moveHistory.emplace_back(arr);
    return newState;
}

string convertBoardToString(const vector<vector<int>> &board)
{
    string result;
    for (const auto &row : board)
    {
        for (int cell : row)
        {
            result += to_string(cell) + ",";
        }
    }
    return result;
}