#include <bits/stdc++.h>
using namespace std;

void make_adj_list_with_weight(vector<vector<pair<int,int> > >& adj, 
    vector<vector<int>>& edges, int n){
        
        vector<pair<int,int>>ans[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            ans[u].push_back({v,weight});
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<ans[i].size(); j++){
                adj[i].push_back(ans[i][j]);
            }
        }
        //checking our work
        cout<<" checking our adj list "<<endl;
        for(int i=0; i<n; i++){
            cout<<i<<"  --> ";
            for(int j=0; j<adj[i].size(); j++){
                cout<<"( "<<adj[i][j].first <<" ,"<<adj[i][j].second<< " )"<<", ";
            }
            cout<<endl;
        }
        return;
    }
    
bool dfs_traversal(unordered_map<int,bool>&visited, stack<int>& st, int src,
        vector<vector<pair<int,int> > >& adj){
    
    visited[src] = 1;
    
    for(int i=0; i<adj[src].size(); i++){
        if( !visited[adj[src][i].first] ){
            bool check = dfs_traversal(visited, st,adj[src][i].first, adj);
            if(check){
                return true;
            }
        }
    }
    st.push(src);
    return false;
}
  
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //make adjecny list
    vector<vector<pair<int,int> > >adj(N);
    make_adj_list_with_weight(adj, edges, N);

    //visited track
    unordered_map<int,bool>visited;
    //stack to store ans
    stack<int>st;
    for(int i=0; i<N; i++){
        if( !visited[i] ){
            dfs_traversal(visited, st, i, adj);
        }
    }
    //now my stack is ready
    vector<int>dis(N,INT_MAX);
    //change the src node as per your choice
    dis[1] = 0;
    while( !st.empty() ){
        int i = st.top();
        st.pop();
        //checking for each neighbour node
        if( dis[i] != INT_MAX ){
            for(int j=0; j<adj[i].size(); j++){
                int new_val = adj[i][j].second + dis[i];
                if(new_val < dis[adj[i][j].first] ){
                    dis[adj[i][j].first] = new_val;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        if(dis[i] > 100000 ){
            dis[i] = -1;
        }
    }
    return dis;
}

//test case copy

// 6 9
// 0 1 5
// 0 2 3
// 1 2 2
// 1 3 6
// 2 3 7
// 2 4 4
// 2 5 2
// 3 4 -1
// 4 5 -2


int main() {
    
   int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; ++i){
        vector<int> temp;
        for(int j=0; j<3; ++j){
            int x; cin>>x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }
    vector<int> res = shortestPath(n, m, edges);
    cout<<" printing ans -> "<<endl;
    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";
}