// using dfs modification -> tarjhan's algorithm


void make_adj_list(vector<vector<int>>& adj,vector<vector<int>> &edges,int v){
    vector<int>ans[v];
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    //fill the adj list
    for(int i=0; i<v; i++){
        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return;
}


void dfs_traversal(int parent, int &time, int src ,vector<int>& low_time,
    vector<int>& disc,vector<int>& visited,vector<vector<int>>& adj,
    vector<vector<int>>& result){

        visited[src] = 1;
        //assign discovery time and lowest possible time to visit
        low_time[src] = time;
        disc[src] = time;
        time++;

        // go for all neighbour node
        for(int i=0; i<adj[src].size(); i++){
            int neighbour = adj[src][i];

            if( !visited[neighbour] ){
                dfs_traversal(src, time, neighbour, low_time, disc, visited, adj, result);
                //if dfs is completed may be it's child have a back edge then child low_time gets updated,
                // so now update mine also if my child node low_time is updated
                low_time[src] = min( low_time[src], low_time[neighbour] );
                //check for bridge
                if( low_time[neighbour] > disc[src]  ){ //only way to reach neighbour is the src node
                    vector<int>temp;
                    temp.push_back(neighbour);
                    temp.push_back(src);
                    result.push_back(temp);
                }
            }
            else{
                //because parent node is already visited
                if( neighbour == parent ){
                    continue;
                }
                // if  we get a node having visited = true and it is adjacent to child means a 
                //Back edge case or we can say a loop where we get a BACK EDGE
                low_time[src] = min( low_time[src], disc[neighbour] ); 
            }
        }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // create adj list
    vector<vector<int>>adj(v);
    make_adj_list(adj,edges,v);
    //lowest time to reach a node
    vector<int>low_time(v,-1);
    //discovery time for each node
    vector<int>disc(v,-1);
    //track visited node
    vector<int>visited(v,0);
    ///track parent
    int parent = -1;
    //track discovery time to visit
    int time = 0;
    //result
    vector<vector<int>> result;
    //handling disconnected graph
    for(int i=0; i<v; i++){
        if( !visited[i] ){
            dfs_traversal(parent, time, i, low_time, disc, visited, adj, result);
        }
    }
    return result;
}