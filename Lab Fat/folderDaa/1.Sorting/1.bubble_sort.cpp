#include<iostream>
#include<vector>
using namespace std;



void bubble_sort(vector<int>&arr,int n){

    for(int i=0;i<n;i++){
        cout<<i<<" "<<n-i-1<<endl;
        for(int j=0;j<n-i-1;j++){
           
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    return;
}

int main(){

    int n;
    cin>>n;


    vector<int>arr(n);

    for(auto &it:arr){
        cin>>it;
    }


    bubble_sort(arr,n);

    for(auto i:arr){
        cout<<i<<" ";
    }

    cout<<endl;
    return 0;


}