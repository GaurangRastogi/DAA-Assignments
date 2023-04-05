#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Fractional Knapsack Problem for an airport permitted baggage scenario
bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    return ((double)(p1.first) / (double)(p1.second)) >= ((double)(p2.first) / (double)(p2.second));
}
double fractional_knapsack(vector<int> &value, vector<int> &weight, int num_baggage, int allowed_weight)
{

    double max_value = 0;

    vector<pair<int, int>> knapsack(num_baggage);

    for (int i = 0; i < num_baggage; i++)
    {
        knapsack[i] = {value[i], weight[i]};
    }

    sort(knapsack.begin(), knapsack.end(), comparator);

    for (int i = 0; i < num_baggage; i++)
    {
        if (knapsack[i].second > allowed_weight)
        {
            max_value += (double)(allowed_weight * knapsack[i].first) / (double)(knapsack[i].second);
            break;
        }
        else
        {
            allowed_weight -= knapsack[i].second;
            max_value += knapsack[i].first;
        }
    }
    return max_value;
}
int main()
{

    cout << "\n\n-----Fractional Knapsack------\n\n";

    int num_baggage;
    cout << "Enter the total number of baggage: ";
    cin >> num_baggage;

    vector<int> weight(num_baggage), value(num_baggage);

    cout << "\nEnter the value of each baggage: ";
    for (int i = 0; i < num_baggage; i++)
    {
        cin >> value[i];
    }

    cout << "\nEnter the weight of each baggage: ";
    for (int i = 0; i < num_baggage; i++)
    {
        cin >> weight[i];
    }

    int allowed_weight;
    cout << "\nEnter the allowed weight: ";
    cin >> allowed_weight;

    cout << "\nMaximum value in Fractional Knapsack is: " << fractional_knapsack(value, weight, num_baggage, allowed_weight);
}
