#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void insertionSort(vector<int>&arr,int n){

    for(int i=0;i<n;i++){
        int j=i;
        while(j>0&&arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

    return;
}

int main(){

    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    insertionSort(arr,n);
    
    for(auto val:arr)
        cout<<val<<" ";
    cout<<endl;
    
    return 0;
}