#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){

    cout<<"\n\n--------------- 0/1 Knapsack -----------------\n\n";

    int n,W;
    cout<<"Enter the number of baggages: ";
    cin>>n;

    vector<int>weight(n),profit(n);
    
    cout<<"Enter the weight of each bag: ";
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    cout<<"Enter the profit of each bag: ";
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }


    cout<<"Enter the total weight allowed: ";
    cin>>W;


    //Making the dyanamic substructure
    //dp[N+1][W+1] -> dp[no_of_items][total_weight]

    vector<vector<int>>dp(n+1,vector<int>(W+1,0));


    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){

            if(weight[i-1]<=j){
                dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<"Maximum profit in the given capacity: "<<dp[n][W]<<endl;

    stack<int>items;
    int i=n,j=W;
    while(i>0&&j>0){
        if(dp[i][j]-dp[i-1][j]!=0){
            items.push(i-1);
            j-=weight[i-1];
        }
        i--;
    }


    cout<<"\n\nInd\tProfit\tWeight\n";
    while(items.size()){
        int ind=items.top();
        cout<<ind<<"\t"<<profit[ind]<<"\t"<<weight[ind]<<endl;
        items.pop();
    }
    return 0;
}