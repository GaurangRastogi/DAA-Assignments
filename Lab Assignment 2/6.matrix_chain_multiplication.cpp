#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int matrix_chain_multiplication(vector<int> &arr, int i, int j)
{
    if (i == j)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], matrix_chain_multiplication(arr, i, k) + matrix_chain_multiplication(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
    }
    return dp[i][j];
}
int main()
{
    cout << "\n\n---------Matrix Chain Multiplication----------\n\n";

    cout << "Enter the value of N: ";
    int n;
    cin >> n;

    cout<<"\nEnter the dimensions of matrices: ";
    vector<int> arr(n);
    for (auto &val : arr)
    {
        cin >> val;
    }

    dp.resize(n + 2, vector<int>(n + 2, -1));

    cout << "The least number of multiplications required are: ";
    cout << matrix_chain_multiplication(arr, 1, n - 1) << endl;
    return 0;
}