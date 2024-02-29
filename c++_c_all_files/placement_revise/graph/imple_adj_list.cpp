// #include <iostream>
// #include<unordered_map>
// #include<list>

// using namespace std;

// class graph{
//     public:

//     unordered_map<int,list<int> >adj;
//     void addEdge(int u, int v, bool direction){
//         adj[u].push_back(v);
//         //if direction = 0 undirected graph
//         //if direction = 1 directed graph
//         if( ! direction ){
//             adj[v].push_back(u);
//         }
//     }

//     void print_graph(){
//         for(auto i: adj){
//             cout<<i.first<<" -> ";
//             for(auto j: i.second){
//                 cout<<j<<"  ";
//             }
//             cout<<endl;
//         }
//     }
// };

// int main(){
//     graph g;
//     int n,m;
//     cout<<"Enter your no of nodes "<<endl;
//     cin>>n;
//     cout<<"Enter your no of edge "<<endl;
//     cin>>m;
//     cout<<"Enter your edge relation "<<endl;
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         bool dir;
//         cin>>u>>v;
//         // cout<<"Enter your direction (directed or not) "<<endl;
//         // cin>>dir;
//         // g.addEdge(u,v,dir);  
//         g.addEdge(u,v,0);  
//     }
//     cout<<"Printing your given graph "<<endl;
//     g.print_graph();
// }


//making the same code in generic way

#include <iostream>
#include<unordered_map>
#include<list>

using namespace std;
template <typename T>

class graph{
    public:

    unordered_map<T,list<T> >adj;
    void addEdge(T u, T v, bool direction){
        adj[u].push_back(v);
        //if direction = 0 undirected graph
        //if direction = 1 directed graph
        if( ! direction ){
            adj[v].push_back(u);
        }
    }

    void print_graph(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<"  ";
            }
            cout<<endl;
        }
    }
};

// 0 1 
// 1 2
// 2 3
// 3 4
// 4 0
// 1 3

int main(){
    graph<int> g;   //here we can generalise if we want a char type also
    int n,m;
    cout<<"Enter your no of nodes "<<endl;
    cin>>n;
    cout<<"Enter your no of edge "<<endl;
    cin>>m;
    cout<<"Enter your edge relation "<<endl;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        bool dir;
        cin>>u>>v;
        // cout<<"Enter your direction (directed or not) "<<endl;
        // cin>>dir;
        // g.addEdge(u,v,dir);  
        g.addEdge(u,v,0);  
    }
    cout<<"Printing your given graph "<<endl;
    g.print_graph();
}