#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 5 4 1 2 7 6 3 8

int partition_for_kth_min(vector<int> &nums, int low, int high)
{
    int pivot = nums[low], st = low, end = high;
    while (st < end)
    {
        while (st <= high && nums[st] <= pivot)
            st++;
        while (end >= low && nums[end] > pivot)
            end--;

        if (st < end)
        {
            swap(nums[st], nums[end]);
        }
    }

    swap(nums[low], nums[end]);
    return end;
}

int kth_min(vector<int> &nums, int n, int k)
{

    int low = 0, high = nums.size() - 1;

    while (true)
    {
        int ind = partition_for_kth_min(nums, low, high);
        if (ind + 1 == k)
            return nums[ind];
        else if (ind + 1 < k)
        {
            low = ind + 1;
        }
        else // ind+1>k
            high = ind - 1;
    }
}

int partition_for_kth_max(vector<int> &nums, int low, int high)
{
    int pivot = nums[low], st = low, end = high;
    while (st < end)
    {
        while (st <= high && nums[st] >= pivot)
            st++;
        while (end >= low && nums[end] < pivot)
            end--;

        if (st < end)
        {
            swap(nums[st], nums[end]);
        }
    }

    swap(nums[low], nums[end]);
    return end;
}
int kth_max(vector<int> &nums, int n, int k)
{
    int low = 0, high = nums.size() - 1;

    while (true)
    {
        int ind = partition_for_kth_max(nums, low, high);
        if (ind + 1 == k)
            return nums[ind];
        else if (ind + 1 < k)
        {
            low = ind + 1;
        }
        else
            high = ind - 1;
    }
}
int main()
{
    cout<<"\n\n--------Kth-Minimum-and-Maximum-in-array--------\n\n";
    
    int n, k;
    cout << "Number of Elements in an array: ";
    cin >> n;

    cout << "\nEnter the k-value: ";
    cin >> k;

    vector<int> nums(n);

    cout<<"\nElements in the array are: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // kth-min element in array
    cout << "\nKth-min element in the array is: " << kth_min(nums, n, k) << endl;

    // kth-max element in array
    cout << "\nKth-max element in the array is: " << kth_max(nums, n, k) << endl<<endl;

    return 0;
}