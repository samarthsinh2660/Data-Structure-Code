#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floyWarshall(vector<vector<int>> dist){
    int V = dist.size();
    // for (int i = 0; i < V; i++)
    //    dist[i][i] = 0;
    for (int k = 0; k < V; k++) {
        //taking one vertex
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination
            // for the above picked source
            for (int j = 0; j < V; j++) {
                // shortest path from
                // i to j 
                if(dist[i][k] != 1e8 && dist[k][j]!= 1e8)
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    
    
    return dist;
}
int main(){
    int INF = 1e8;
    
    // int n;
    // cout<<"enter the number of the vertices:- ";
    // cin>>n;
    // //Creates a temporary vector<long long> of size n, where every element is initialized to INF
    // vector<vector<int>> dist(n, vector<int>(n, INF));
    // int v,u,w;
    // //v->u with w
    // cout<<"enter the vertex, edge, weight"<<endl;
    // for(int i = 0 ; i < n ; i++){
    //    cin>>v>>u>>w;
    //    dist[v][u] = min(dist[v][u], w);
    // }
    vector<vector<int>> dist = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };

    vector<vector<int>> ans = floyWarshall(dist);
    for(int i =0 ; i < ans.size() ; i++){
        for(int j =0 ; j < ans.size(); j++){
            if(ans[i][j] == INF){
                cout<<"INF ";
            }
            else{
                cout<<ans[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}