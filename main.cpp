#include <iostream>
#include <bits/stdc++.h>
#include "levels.cpp"
#include "serach_algorithms\solutionByBFS.cpp"
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    for (int k = 0; k < LEVELS.size(); ++k)
    {
        auto phase = LEVELS[k];
        setColor("blue");
        cout << shifting(45) << "Level " << k + 1 << " started \n\n\n";
        resetColor();
        int current = counts[k];
        while (!isSolved(phase) && current > 0)
        {
            int x1, y1, x2, y2;
            setColor("green");
            cout << shifting(45) << "Your moves: " << current << "\n\n";
            resetColor();
            display(phase);
            setColor("yellow");
            cout << "\n"
                 << shifting(35) << "Enter the piece you want to move: \n";
            resetColor();
            while (1)
            {
                cout << shifting(35);
                cin >> x1 >> y1;
                if (isMovable(phase[x1 - 1][y1 - 1]))
                    break;
                setColor("red");
                cout << "\n"
                     << shifting(35) << "Invalid input!!, Try again\n";
                resetColor();
            }
            setColor("yellow");
            cout << "\n"
                 << shifting(35) << "Enter the destenation: \n";
            resetColor();
            while (1)
            {
                cout << shifting(35);
                cin >> x2 >> y2;
                if (move(x1 - 1, y1 - 1, x2 - 1, y2 - 1, phase))
                    break;
                setColor("red");
                cout << "\n"
                     << shifting(35) << "Invalid input!!, Try again\n";
                resetColor();
            }
            current--;
        }
        if (!isSolved(phase))
        {
            setColor("red");
            cout << "\n\n"
                 << shifting(35) << "Ops !!\nOUT OF MOVES !!\nTry again\n\n ";
            --k;
            resetColor();
            continue;
        }
        cout << "\n\n\n";
        setColor("blue");
        cout << shifting(35) << "Level Completed " << k + 1 << " :) ";
        resetColor();
        cout << "\n\n\n"
             << shifting(35) << "_____________________________________________________________\n\n\n";
    }
}

int main()
{
    display(LEVELS[2]);
    solveGame(LEVELS[2]);
    return 0;
}