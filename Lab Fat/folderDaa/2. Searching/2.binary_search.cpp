#include<iostream>
#include<vector>
using namespace std;

bool binary_search(vector<int>&arr,int key){

    int low=0,high=arr.size()-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==key)
            return true;
        else if(arr[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return false;
}

int main(){

    int n;
    cin>>n;

    //array should be sorted
    vector<int>arr(n);

    for(auto &it:arr)
        cin>>it;

    int key;
    cin>>key;


    bool find=binary_search(arr,key);

    if(find)
        cout<<"Element found\n";
    else    
        cout<<"Element not found\n";
    return 0;
}