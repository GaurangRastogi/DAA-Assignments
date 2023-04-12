#include<iostream>
#include<vector>
using namespace std;

void min_max(vector<int>&arr,int st,int end,int &mn,int &mx){

    if(st==end){
        mn=mx=arr[st];
        return;
    }
    else{

        int mid=(st+end)/2,mn1,mn2,mx1,mx2;
        min_max(arr,st,mid,mn1,mx1);
        min_max(arr,mid+1,end,mn2,mx2);

        if(mn1<mn2){
            mn=mn1;
        }else{
            mn=mn2;
        }

        if(mx1<mx2){
            mx=mx2;
        }
        else{
            mx=mx1;
        }
        return;
    }
}
int main(){

    int n;
    cin>>n;

    vector<int>arr(n);
    
    for(auto &it:arr)
        cin>>it;



    int mn,mx,st=0,end=n-1;

    min_max(arr,st,end,mn,mx);

    cout<<"Min: "<<mn<<endl;
    cout<<"Max: "<<mx<<endl;
    return 0;
}