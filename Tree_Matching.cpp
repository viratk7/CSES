// Tree Matching
// CSES ID: 1130
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

    vector<int> parent(n+1,-1);
    vector<vector<long long>> dp(n+1,vector<long long>(2,0));

    function<void(int)> dfs=[&](int node){
        for(int child:tree[node]){
            if(child!=parent[node]){
                parent[child]=node;
                dfs(child);            
            }
        }
        for(int child:tree[node]){
            if(child!=parent[node]){
                dp[node][0]+=max(dp[child][0],dp[child][1]);
            }
        }
        for(int child:tree[node]){
            if(child!=parent[node]){
                dp[node][1]=max(dp[node][1],1+dp[node][0]-max(dp[child][0],dp[child][1])+dp[child][0]);
            }
        }
    };
    dfs(1);

    cout<<max(dp[1][0],dp[1][1])<<endl;

    return 0;
}
