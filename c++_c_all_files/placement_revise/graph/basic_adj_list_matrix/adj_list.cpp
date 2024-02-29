#include<iostream>
#include<vector>
using namespace std;

// 0 1 
// 1 2
// 2 3
// 3 4
// 4 0
// 1 3

// adjency list

int main(){

    int n,m;
    cout<<"Enter your no of nodes "<<endl;
    cin>>n;
    cout<<"Enter your no of edge "<<endl;
    cin>>m;
    cout<<"Enter your edge relation "<<endl;
    vector<int>ans[n];
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        //for undirected
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    //printing function
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" ---> ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

//adjency matrix

// int main(){

//     int n,m;
//     cout<<"Enter your no of nodes "<<endl;
//     cin>>n;
//     cout<<"Enter your no of edge "<<endl;
//     cin>>m;
//     cout<<"Enter your edge relation "<<endl;
//     int ans[n][n];
//     //initialise all to 0
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             ans[i][j] = 0;
//         }
//     }
    
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         //for undirected
//         ans[u][v] = 1;
//         ans[v][u] = 1;
//     }
//     //printing function
//     cout<<"printing adjency matrix "<<endl;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



