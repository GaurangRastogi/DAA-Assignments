#include <iostream>
#include <vector>
using namespace std;

int main()
{

    cout << "\n\n---------------Longest Common Subsequences-----------------\n\n";

    string st1, st2;

    cout << "Enter first sequence: ";
    cin >> st1;

    cout << "Enter second sequence: ";
    cin >> st2;

    int n = st1.size(), m = st2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {

            if (st1[i - 1] == st2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << "Length of longest common subsequences: " << dp[n][m] << endl;

    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {

        if (st1[i - 1] == st2[j - 1])
        {
            lcs = st1[i - 1] + lcs;
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    cout <<"Longest Common Subsequence is:"<<lcs << endl;

    return 0;
}