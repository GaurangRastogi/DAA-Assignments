#include<iostream>
using namespace std;
int main(){

    cout<<"\n------------String Matching - Naive Approach--------------------\n\n";

    string text,pattern;
    cout<<"Enter the text: ";
    cin>>text;

    cout<<"Enter the pattern: ";
    cin>>pattern;


    int n=text.size(),m=pattern.size();

    for(int i=0;i<n;i++){
        int flag=1;
        for(int j=0;j<m;j++){
            if(text[i+j]!=pattern[j]){
                flag=0;
                break;
            }
        }

        if(flag==1){
            cout<<"String matched at index(after shift): "<<i<<endl;
        }
    }

    return 0;
}