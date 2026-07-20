// Building Teams
// CSES ID: 1668
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS finds if valid 2 coloring is possible
    // 0:red and 1:blue
    vector<int> color(n+1,-1);
    bool valid=true;

    for(int u=1;u<=n;u++){
        // start BFS
        if(color[u]==-1){
            queue<int> q;
            color[u] = 0;
            q.push(u);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for(int neigh:adj[x]){
                    int neigh_color=abs(1-color[x]);
                    if(color[neigh]==-1){
                        q.push(neigh);
                        color[neigh]=neigh_color;
                    }
                    else if(color[neigh]==abs(1-neigh_color)){
                        valid=false;
                        break;
                    }
                }
            } 
        }
        if(!valid){
            break;
        }
    }
    if(!valid){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<color[i]+1<<" ";
        }
    }
    return 0;
}
