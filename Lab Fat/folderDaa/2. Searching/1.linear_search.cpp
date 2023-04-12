#include<iostream>
#include<vector>
using namespace std;


bool linear_search(vector<int>&arr,int key){

    for(auto it:arr){
        if(it==key)
            return true;
    }
    return false;
}

int main(){

    int n;
    cin>>n;

    vector<int>arr(n);
    for(auto &it:arr)
        cin>>it;

    int key;
    cin>>key;

    bool find=linear_search(arr,key);

    if(find)
        cout<<"Key found\n";
    else    
        cout<<"Key not found\n";

    return 0;
}