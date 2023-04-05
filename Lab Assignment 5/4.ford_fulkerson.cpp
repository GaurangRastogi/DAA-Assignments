#include<iostream>
#include<bits/stdc++.h>
using namespace std;



//if we can reach sink from source return true
//else if it is not possible retur false;
 
bool bfs(vector<vector<int>>&resiGraph,int V,int source,int sink,vector<int>&parent){

    vector<bool>visited(V,false);

    queue<int>q;
    visited[source]=true;
    q.push(source);
    parent[source]=-1;

    while(q.size()){

        int u=q.front();
        q.pop();

        for(int v=0;v<V;v++){
            if(visited[v]==false&&resiGraph[u][v]>0){
                parent[v]=u;
                if(v==sink){
                    return true;
                }
                q.push(v);
                visited[v]=true;
            }
        }
    }
    return false;
}
int fordFulkerson(vector<vector<int>>&graph,int V,int source,int sink){


    vector<vector<int>>resiGraph(V);
    vector<int>parent(V);

    for(int i=0;i<V;i++){
        vector<int>row;
        for(int j=0;j<graph[i].size();j++){
            row.push_back(graph[i][j]);
        }

        resiGraph.push_back(row);
    }

    int max_flow=0;

    while(bfs(resiGraph,V,source,sink,parent)){

        int path_flow=INT_MAX;

        for(int v=sink;v!=source;v=parent[v]){
            int u=parent[v];
            path_flow=min(path_flow,resiGraph[u][v]);
        }

        for(int v=sink;v!=source;v=parent[v]){
            int u=parent[v];
            resiGraph[u][v]-=path_flow;
            resiGraph[u][v]+=path_flow;
        }

        max_flow+=path_flow;
    }

    return max_flow;
}
int main(){

    int V;
    cin>>V;

    vector<vector<int>>graph(V);

    //enter the number of edges in graph
    int edges,a,b;
    cin>>edges;

    for(int i=0;i<edges;i++){
        cin>>a>>b;
        graph[a].push_back(b);
    }

    int s,t;
    cout<<"Enter source and sink: "; 
    cin>>s>>t;
    cout<<"The possible maximum flow is "<<fordFulkerson(graph,V,s,t)<<endl;
    return 0;
}
