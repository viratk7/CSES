// Message Route
// CSES ID: 1667
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS finds shortest path in equal weight graph
    vector<int> parent(n+1,-1);

    // start BFS
    queue<int> q;
    visited[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        if (x == n){
            break;
        }
        q.pop();
        for(int neigh:adj[x]){
            if(!visited[neigh]){
                q.push(neigh);
                visited[neigh]=true;
                parent[neigh]=x;
            }
        }
    }
    if (parent[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int> ans;
        int curr_node=n;
        while (curr_node!=1){
            ans.push_back(curr_node);
            curr_node=parent[curr_node];
        }
        ans.push_back(1);
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}

    

