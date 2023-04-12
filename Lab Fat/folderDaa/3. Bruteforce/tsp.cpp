#include<bits/stdc++.h>
using namespace std;

int ans=1e9;


void tsp(vector<vector<int>>&graph,int n,int vertex,vector<int>visited,int count,int distance){

   
    if(count==n){
        distance+=graph[vertex][0];
        ans=min(ans,distance);
        // return;
    }
    visited[vertex]=1;
    for(int i=0;i<n;i++){
        if(i!=vertex&&visited[i]==0){
            tsp(graph,n,i,visited,count+1,distance+graph[vertex][i]);
        }
    }
    return;
}
int main(){


    int n;
    cin>>n;

    vector<vector<int>>graph(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    vector<int>visited(n,0);


    int src=0,count=1,distance=0;
    tsp(graph,n,src,visited,count,distance);
    
    cout<<ans<<endl;
}