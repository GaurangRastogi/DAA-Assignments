#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>&arr,int st,int end){

    int random=  st+ (rand() % end);
    int pivot=st;

    //instead of st as pivot, taking random as pivot,
    // kind-of randomized quick sort
    swap(arr[random],arr[pivot]);
   

    while(st<end){

        while(arr[st]<=arr[pivot]){
            st++;
        }

        while(arr[pivot]<arr[end]){
            end--;
        }

        if(st<end){
            swap(arr[st],arr[end]);
        }

    }

    //end location must have pivot always 
    swap(arr[pivot],arr[end]);
    return end;
}
void quickSort(vector<int>&arr,int st,int end){

    if(st<end){
        int mid=partition(arr,st,end);
        quickSort(arr,st,mid-1);
        quickSort(arr,mid+1,end);
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


    int l=0,h=n-1;
    quickSort(arr,l,h);

    cout<<"Sorted output using quickSort: ";
    for(auto val:arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}