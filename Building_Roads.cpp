// Building Roads
// CSES ID: 1666
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1,false);
    for(int k=0;k<m;k++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //print no. of components (n components, then n(n+1)/2 roads)
    vector<int> components;
    for(int u=1;u<=n;u++){
        if(!visited[u]){
            components.push_back(u);
            //start dfs loop
            stack<int> st;
            st.push(u);
            visited[u]=true;
            while(!st.empty()){
                int curr_node=st.top();
                st.pop();
                //iterate over all neighbours
                for(int k=0;k<adj[curr_node].size();k++){
                    int neigh=adj[curr_node][k];
                    if(!visited[neigh]){
                        visited[neigh]=true;
                        st.push(neigh);
                    }
                }
            }
        }
    }

    int comps=components.size();
    cout<<(comps-1)<<endl;
    for(int i=0;i<components.size()-1;i++){
        cout<<components[i]<<" "<<components[i+1]<<endl;
    }

    return 0;
}
