#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>&arr,int n){

    for(int i=0;i<n;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }

        //swap element at minIdx and i
        int temp=arr[minIdx];
        arr[minIdx]=arr[i];
        arr[i]=temp;
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


    selectionSort(arr,n);

    for(auto val:arr){
        cout<<val<<" ";
    }

    cout<<endl;
    return 0;
}