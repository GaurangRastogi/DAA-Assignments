#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int travelling_salesman(int city, int cityMask, int cities, vector<vector<int>> &adj_matrix, vector<vector<int>> &dp)
{

    cityMask &= (~(1 << city));

    if (!cityMask)
        return adj_matrix[city][0];

    else if (dp[city][cityMask] != -1)
        return dp[city][cityMask];

    else
    {

        int ans = INT_MAX;
        for (int ind = 0; ind < cities; ind++)
        {

            if (cityMask & (1 << ind))
            {
                ans = min(ans, adj_matrix[city][ind] + travelling_salesman(ind, cityMask, cities, adj_matrix, dp));
            }
        }

        return dp[city][cityMask] = ans;
    }
}

int main()
{

    cout << "\n--------Travelling Salesman Problem----------\n\n";

    int cities;
    cout << "\nNumber of cities in the Graph: ";
    cin >> cities;

    vector<vector<int>> adj_matrix(cities, vector<int>(cities, 0));

    vector<vector<int>> dp(cities + 1, vector<int>((1 << (cities + 1)), -1));

    cout << "\nEnter the weight of edge b/n each cities\n";
    for (int i = 0; i < cities; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            cin >> adj_matrix[i][j];
        }
    }

    int cityMask = (1 << cities) - 1;

    int min_cost = travelling_salesman(0, cityMask, cities, adj_matrix, dp);

    cout << "Minimum cost to travel all the cities once and come back to starting city is: " << min_cost << endl;
    return 0;
}