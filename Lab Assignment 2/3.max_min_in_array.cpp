#include<bits/stdc++.h>
using namespace std;

int mn,mx;
void min_max(vector<int>&arr,int l,int h,int &mn,int &mx){
    if(l==h){
        mn=mx=arr[l];
        return;
    }
    else{
        int mid=(l+h)/2,mn1,mn2,mx1,mx2;
        min_max(arr,l,mid,mn1,mx1);
        min_max(arr,mid+1,h,mn2,mx2);

        if(mn1<mn2){
            mn=mn1;
        }
        else{
            mn=mn2;
        }

        if(mx1<mx2){
            mx=mx2;
        }
        else{
            mx=mx1;
        }
    }
}
int main(){

    cout<<"\n\n---------Min-Max Algorithm---------\n\n";

    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the element of the array: ";


    vector<int>arr(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    min_max(arr,0,n-1,mn,mx);
    cout<<"\nMinimum number is: "<<mn<<"\n\nMaximum number is : "<<mx<<endl;

    return 0;
}