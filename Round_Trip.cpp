// Round Trip
// CSES ID: 1669
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n+1,false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n+1,-1);
    int end_node=-1;

    for(int u=1;u<=n;u++){
        // start BFS
        if(!visited[u]){
            stack<int> st;
            visited[u] = true;
            st.push(u);
            while (!st.empty())
            {
                int curr_node = st.top();
                st.pop();
                for(int neigh:adj[curr_node]){
                    if(!visited[neigh]){
                        st.push(neigh);
                        visited[neigh]=true;
                        parent[neigh]=curr_node;
                    }
                    else if(neigh!=parent[curr_node]){
                        end_node=curr_node;
                        break;
                    }
                }
            } 
        }
        if(end_node!=-1){
            break;
        }
    }
    if(end_node==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        int curr_node=end_node;
        while(curr_node!=-1){
            cout<<curr_node<<" ";
            curr_node=parent[curr_node];
        }
        cout<<end_node<<endl;
    }
    return 0;
}
