#include<iostream>
#include<vector>
using namespace std;

void shortest_distance(vector<vector<int>>&cost){
    int n=cost.size();


    //initialization
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cost[i][j]==-1){
                cost[i][j]=1e9;
            }

            if(i==j)
                cost[i][j]=0;  //cost of going fromm city i to i
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //base condition
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }


    //updation 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cost[i][j]==1e9){
                cost[i][j]=-1; //not reachable
            }
        }
    }

    cout<<"Floyd Warshall distance matrix: \n\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }


    //if negative cycle
    for(int i=0;i<n;i++){
        if(cost[i][i]<0){
            cout<<"\nIt also contains negative cycle";
        }
    }

    return;

}

void floyd_main(vector<vector<int>>&edges,int V,int E){

    vector<vector<int>>adj_matrix(V,vector<int>(V,-1));

    for(int i=0;i<E;i++){
        adj_matrix[edges[i][0]][edges[i][1]]=edges[i][2];
    }


    cout<<"Enter src:";
    int src;
    cin>>src;
    
    shortest_distance(adj_matrix);

}

int main(){
    cout<<"-----------Floyd Warshall Algorithm----------------\n\n";
    int V,E,st,end,weight;
    cout<<"Enter the number of vertex and edges: ";
    cin>>V>>E;


    vector<vector<int>>edges(E,vector<int>(3));

    cout<<"\n---Enter edge (u,v) and weight---\n";
    for(int i=0;i<E;i++){
        cin>>st>>end>>weight;
        edges[i][0]=st;
        edges[i][1]=end;
        edges[i][2]=weight;
    }

   floyd_main(edges,V,E);
    return 0;
}