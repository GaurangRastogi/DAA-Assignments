#include <iostream>
#include <vector>
using namespace std;
int  travelling_salesman_path= 1e5;
void travel(int count, int vertex, int vertices, vector<vector<int>> &adj_matrix, vector<bool> visited, int distance)
{
    if (count == vertices)
    {
        distance += adj_matrix[vertex][0];
        travelling_salesman_path = min(travelling_salesman_path, distance);
    }
    visited[vertex] = true;
    for (int i = 0; i < vertices; i++)
    {
        if (i != vertex && visited[i] == false)
        {
            travel(count + 1, i, vertices, adj_matrix, visited, distance + adj_matrix[vertex][i]);
        }
    }
}

int main()
{

    cout << "\n-----Travelling Salesman Bruteforce Approach------\n";

    int vertices;
    cout << "\nNumber of vertices in the Graph: ";
    cin >> vertices;

    vector<vector<int>> adj_matrix(vertices, vector<int>(vertices, 0));

    vector<bool> visited(vertices, false);

    cout << "\nEnter the weight of edge b/n each vertices\n";
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> adj_matrix[i][j];
        }
    }

    travel(1, 0, vertices, adj_matrix, visited, 0);
    cout <<"\n\nTravelling Salesman will cost ("<<travelling_salesman_path<<") to travel all cities exactly once and return to starting city.\n"<<endl;
}

// 0 20 10 12
// 20 0 15 11
// 10 15 0 17
// 12 11 17 0