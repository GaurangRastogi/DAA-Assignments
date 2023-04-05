#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans{};
void backtrack(vector<vector<int>> &chess, int col, int n, vector<int> &temp, vector<int> &samerow, vector<int> &up, vector<int> &down)
{
    if (col == n)
    {
        ans.push_back(temp);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (samerow[row] == 0 && down[col + row] == 0 && up[(n - 1) + (col - row)] == 0)
        {
            // cout<<row<<" "<<col<<endl;
            chess[row][col] = 1;
            temp.push_back(row + 1);
            samerow[row] = 1;
            up[(n - 1) + (col - row)] = 1;
            down[col + row] = 1;
            backtrack(chess, col + 1, n, temp, samerow, up, down);
            chess[row][col] = 0;
            temp.pop_back();
            samerow[row] = 0;
            up[(n - 1) + (col - row)] = 0;
            down[col + row] = 0;
        }
    }
    return;
}
vector<vector<int>> nQueen(int n)
{

    vector<vector<int>> chess(n, vector<int>(n, 0));
    vector<int> temp{};
    vector<int> samerow(n, 0), up(2 * n - 1, 0), down(2 * n - 1, 0);
    backtrack(chess, 0, n, temp, samerow, up, down);
    return ans;
}
int main()
{

    cout << "\n\n----------N_Queens Problem-----------\n\n";
    int n;
    cout << "Enter the dimension of chess: ";
    cin >> n;

    vector<vector<int>> possiblePostions = nQueen(n);
    cout << "\n------Possible Postions of N-queens (in each column) one queen and their row postions are-------\n\n";

    cout << "\t\t";
    for (int i = 0; i < n; i++)
    {
        cout << "C" << i + 1 << "\t";
    }
    cout << endl << endl;

    for (int i = 0; i < possiblePostions.size(); i++)
    {
        cout << "\t\t";
        for (int j = 0; j < n; j++)
        {
            cout << possiblePostions[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << endl << endl << endl;

    return 0;
}