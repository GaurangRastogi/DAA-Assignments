#include<iostream>
#include<vector>
using namespace std;


void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
    return;
}
void insertion_sort(vector<int>&arr,int n){
    
    int key,j;

    for(int i=0;i<n;i++){
        j=i;
        while(j>0&&arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    return;
}

int main(){
    cout<<"------Insertion Sort (Brute-force Solution for Sorting)------";
    int n;
    cout<<"\nEnter the number of element in the array: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"\nEnter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    insertion_sort(arr,n);

    cout<<"\nSorted Array is as follows: ";
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}