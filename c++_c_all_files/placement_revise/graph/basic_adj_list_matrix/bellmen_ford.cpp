#include<bits/stdc++.h>
using namespace std;
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    //dis
    vector<int>dis(V,1e8);
    dis[S] = 0;
    //traverse for n-1 times
    for(int i=0; i<V; i++){
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if( (dis[u] != 1e8) && ( dis[u] + w < dis[v] ) ){
                dis[v] = dis[u] + w ;
            }
        }
    }
    bool flag = false;
    //detect negative cycle
    for(int j=0; j<edges.size(); j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        
        if( (dis[u] != 1e8) && ( dis[u] + w < dis[v] ) ){
            dis[v] = dis[u] + w ;
            flag = true;
        }
    }
    if(flag){
        vector<int>ans;
        ans.push_back(-1);
        return ans;
    }
    return dis;
}

// 2 1
// 0 1 9
// 0

int main() {
    int N, m;
    cin >> N >> m;
    vector<vector<int>> edges;

    for (int i = 0; i < m; ++i) {
        vector<int> temp;
        for (int j = 0; j < 3; ++j) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }

    int src;
    cin >> src;

    vector<int> res = bellman_ford(N, edges, src);
    cout<<"Result -> ";
    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}