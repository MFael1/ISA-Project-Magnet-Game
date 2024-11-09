#include <iostream>
#include <vector>
#include "uitls_functions.cpp"
void solveGame(const vector<vector<int>> &v)
{
    queue<State> q;
    unordered_set<string> visited; 

    State start = {v, {}};
    q.push(start);

    while (!q.empty())
    {
        State current = q.front();
        q.pop();

        if (isSolved(current.v))
        {
            cout << "Solution found!\n";
            for (auto move : current.moveHistory)
            {
                cout << "Move from (" << move[0] + 1 << ", " << move[1] + 1 << ") ----> to (" << move[2] + 1<< ", " << move[3] + 1 << ") \n";
            }
            return;
        }

        for (int i = 0; i < current.v.size(); ++i)
        {
            for (int j = 0; j < current.v[0].size(); ++j)
            {
                if (isMovable(current.v[i][j]))
                { 
                    auto moves = getValidMoves(i, j, current.v);
                    for (auto [x, y] : moves)
                    {
                        State newState = applyMove(current, i, j, x, y);
                        string vStr = convertBoardToString(newState.v);
                        if (visited.find(vStr) == visited.end())
                        {
                            q.push(newState);
                            visited.insert(vStr);
                        }
                    }
                }
            }
        }
    }
    cout << "No solution found.\n";
}
