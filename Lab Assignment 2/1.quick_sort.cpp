#include<bits/stdc++.h>
using namespace std;


class Mobile{
public:
    string name,brand;
    int size,price;
    Mobile(){
        name="";
        brand="";
        size=0;
        price=0;
    }
};

int partition(vector<Mobile>&arr,int low,int high){

    int st=low,end=high,pivot=arr[low].size;
   while(st<end){
       while(arr[st].size<=pivot)    st++;
       while(arr[end].size>pivot)    end--;
       if(st<end)   swap(arr[st],arr[end]);
   }
   swap(arr[low],arr[end]);
   return end;

}

void quickSort(vector<Mobile>&arr,int low,int high){
     if(low<high){
        int ind=partition(arr,low,high);
        quickSort(arr,low,ind-1);
        quickSort(arr,ind+1,high);
    }
}
int main(){

    cout<<endl<<endl<<"-------------Quick Sort--------------"<<endl<<endl;

    cout<<"\n\t\tEnter the memory of phones in gigabytes\n"<<endl;

    cout<<"Enter the number of mobile phones: ";
    int n;
    cin>>n;

    cout<<endl<<"------Enter the specification of Mobile-------"<<endl<<endl;

    Mobile mobile;
    vector<Mobile>arr;
    for(int i=0;i<n;i++){
        cout<<"\nEnter "<<i+1<<"th mobile specification\n";
        cout<<"Name: ";
        cin>>mobile.name;
        cout<<"Brand: ";
        cin>>mobile.brand;
        cout<<"Price: ";
        cin>>mobile.price;
        cout<<"Size: ";
        cin>>mobile.size;

        arr.push_back(mobile);
    }


    quickSort(arr,0,n-1);
    cout<<endl<<"Sorted Array is this: "<<endl;

    for(auto mobile:arr){
        cout<<"Name: "<<mobile.name<<"\tBrand: "<<mobile.brand;
        cout<<"\tPrice: "<<mobile.price<<"\tSize: "<<mobile.size<<endl;
    }
    cout<<endl;
    return 0;
}