#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
int ans_ls = -1, ans_bs = -1;

int recursive_ls(vector<int> &arr, int ind, int val)
{
    if (ind < 0)
        return 0;
    else if (arr[ind] == val)
    {
        ans_ls = ind;
        return 1;
    }
    else
    {
        return 1 + recursive_ls(arr, ind - 1, val);
    }
}

void linear_search(vector<int> &arr, int n, int val)
{
    int comparisions = recursive_ls(arr, n - 1, val);

    cout << "\nComparisions in Linear Recursive Search is: " << comparisions << endl;

    if (ans_ls == -1)
    {
        cout << "\nElement not found";
    }
    else
    {
        cout << "\nElement is at index: " << ans_ls;
    }
}

int recursive_bs(vector<int> &arr, int low, int high, int val)
{
    if (high < low)
        return 0;

    int mid = (low + high) / 2;

    if (arr[mid] == val)
    {
        ans_bs = mid;
        return 1;
    }
    else
    {

        if (arr[mid] > val)
        {
            return 1 + recursive_bs(arr, low, mid - 1, val);
        }
        else
        {
            return 1 + recursive_bs(arr, mid + 1, high, val);
        }
    }
}

void binary_search(vector<int> &arr, int n, int val)
{
    sort(arr.begin(),arr.end());

    int comparisions = recursive_bs(arr, 0, n - 1, val);

    cout << "\nComparisions in Binary Recursive Search is: " << comparisions << endl;

    if (ans_bs == -1)
    {
        cout << "\nElement not found";
    }
    else
    {
        cout << "\nElement is at index: " << ans_bs;
    }
}

int main()
{

    cout<<"-------Recursive Linear & Binary Search--------\n";
    int n, val;
    cout << "\n----Enter Values---";
    cout << "\nNumber of Element in the array: ";
    cin >> n;
    cout << "Value to be searched: ";
    cin >> val;

    vector<int> arr(n);
    cout << "Elements in the array are: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n----Linear Search Results ----";
    linear_search(arr, n, val);

    cout << "\n----Binary Search Results ----";
    binary_search(arr, n, val);

    cout<<endl;
    return 0;
}
