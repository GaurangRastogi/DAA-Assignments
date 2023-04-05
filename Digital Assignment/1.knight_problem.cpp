/*
Problem:

Given a N*N board with the Knight placed on the first block
of an empty board. Moving according to the rules of chess
knight must visit each square exactly once. Print the order
of each cell in which they are visited.



It should be noted that knight's tour graph solution is a bipartite graph

-> Such that it can be coloured using two colors namely black and white

From black, knight go to white and vice-versa

*/

#include <bits/stdc++.h>
using namespace std;

bool valid(int a, int b)
{
    // check validity
    if (a < 0 || a > 7 || b < 0 || b > 7)
        return false;

    return true;
}

bool backtrack(vector<vector<int>> &chess, vector<pair<int, int>> &moves, int i, int j)
{
    // ans found
    if (chess[i][j] == 63)
        return true;

    else
    {
        bool flag = false;

        for (int k = 0; k < moves.size(); k++)
        {
            int a = i + moves[k].first, b = j + moves[k].second;
            // if valid.. and not already visited
            if (valid(a, b) && chess[a][b] == -1)
            {
                chess[a][b] = chess[i][j] + 1;

                // recurse for next moves
                flag = backtrack(chess, moves, a, b);

                // if solution not found..backtrack
                if (!flag)
                    chess[a][b] = -1;

                // break..return
                else
                    break;
            }
        }
        return flag;
    }
}

int main()
{
    vector<vector<int>> chess(8, vector<int>(8, -1));

    vector<pair<int, int>> moves = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

    chess[0][0] = 0;

    backtrack(chess, moves, 0, 0);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}