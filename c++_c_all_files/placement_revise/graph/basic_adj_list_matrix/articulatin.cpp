#include<bits/stdc++.h>
using namespace std;

void dfs_traversal(int src, vector<int>& disc, vector<int>& low_time,
    vector<bool>& visited,int &timer,int parent, vector<int>& ans,
        vector<int>adj[] ){
    
    visited[src] = 1;
    //taking care of root node
    int child = 0;
    //disc and low time updation
    disc[src] = timer;
    low_time[src] = timer;
    timer++;
    // traverse and check for all neighbour
    for(int i=0; i<adj[src].size(); i++){
        int nbr = adj[src][i];
        //if not visited
        if( !visited[nbr] ){
            //call dfs
            dfs_traversal(nbr,disc,low_time,visited,timer,src,ans,adj);
            //while return from dfs if child node low_time gets update by back edge
            //update mine also
            low_time[src] = min( low_time[src], low_time[nbr] );
            //if we have articulation point track
            if( low_time[nbr] >= disc[src] && parent != -1){
                ans[src] = 1;
            }
            child++;
            
        }
        else{
            //already visited node
    
            //if visted and it's parent of nbr then ignore
            if( parent == nbr ){
                continue;
            }
            //back edge case if any nbr is not a parent and it's low time is less
            //then upate the lowtime of that node
            low_time[src] = min( disc[nbr], low_time[src] );
        }
    }
    if(parent == -1 && child > 1){
        ans[src] = 1;
    }
}

vector<int> articulationPoints(int V, vector<int>adj[]) {
    //we have adj list already
    // when we first discover the node
    vector<int>disc(V,-1);
    // lowest possible time to reach a node update when we get back edge or my 
    // child get a back edge
    vector<int>low_time(V,-1);
    //visited track
    vector<bool>visited(V,0);
    //keep track of time to visit
    int timer = 0;
    //keep track of parent node
    int parent = -1;
    //create an ans vector to stroe articulation point
    vector<int>ans(V,0);
    //handling any already disconnected comp of graph
    for(int i=0; i<V; i++){
        if( !visited[i] ){
            dfs_traversal(i,disc,low_time,visited,timer,parent,ans, adj);
        }
    }
    // in sorted manner
    vector<int>result;
    for(int i=0; i<V; i++){
        if( !ans[i] ){
            continue;
        }
        result.push_back(i);
    }
    if(result.size() == 0){
        result.push_back(-1);
    }
    return result;
}
//test case

// 5 5
// 0 1
// 1 4
// 2 4
// 3 4
// 2 3

int main(){
	int V, E;
    cin >> V >> E;
    vector<int>adj[V];
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = articulationPoints(V, adj);
    cout<<" Atriculation points in the graph are: "<<endl;
    for(auto i: ans)cout << i << " ";
    cout << "\n";
	return 0;
}