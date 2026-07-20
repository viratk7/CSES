// Subordinates
// CSES ID: 1674
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<vector<int>> tree;
    vector<long long> ans;

    cin>>n;
    
    tree.assign(n + 1, {});
    ans.assign(n + 1, 0);

    for(int i=2;i<=n;i++){
        int par;
        cin>>par;
        tree[par].push_back(i);
    }

    function<long long(int)> dfs=[&](int node){
        long long subs=0;
        for(int child:tree[node]){
            subs+=dfs(child);
        }
        ans[node]=subs;
        return subs+1;
    };

    //run dfs starting from 1
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
