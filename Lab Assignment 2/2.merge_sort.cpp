#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{

    int n1 = mid-st+1, n2 = end - mid;
    vector<int> L(n1, 0), R(n2, 0);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[st + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = st;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
    return;
}

void mergeSort(vector<int> &arr, int st, int end)
{

    if (st < end)
    {
        int mid = (st + end) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main()
{

    cout << "\n\n-----------Merge Sort---------\n\n";

    cout << "Enter the elements in the array: ";
    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array : ";

    for (auto i : arr)
        cout << i << " ";

    cout << endl;
    return 0;
}