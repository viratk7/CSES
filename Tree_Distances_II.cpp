// Tree Distances II
// CSES ID: 1133
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    visited[1]=true;
    vector<int> subtree(n+1,0);

    function<int(int)> dfs=[&](int node){
        for(int child:tree[node]){
            if(!visited[child]){
                visited[child]=true;
                subtree[node]+=dfs(child);
            }
        }
        return 1+subtree[node];
    };
    dfs(1);

    visited= vector<bool>(n+1,false);
    visited[1]=true;
    long long sum = 0;

    function<void(int,int)> sum_dfs = [&](int node, int depth){
        sum += depth;

        for(int child : tree[node]){
            if(!visited[child]){
                visited[child] = true;
                sum_dfs(child, depth + 1);
            }
        }
    };
    sum_dfs(1,0);

    vector<long long> ans(n+1);
    visited= vector<bool>(n+1,false);
    visited[1]=true;
    ans[1]=sum;

    function<void(int,int)> final_dfs=[&](int node,int parent){
        if(node!=1){
            ans[node]=ans[parent]+n-2*subtree[node]-2;
        }
        visited[node]=true;
        for(int child:tree[node]){
            if(!visited[child]){
                final_dfs(child,node);
            }
        }
    };
    final_dfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}
