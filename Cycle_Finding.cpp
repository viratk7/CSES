// Cycle Finding
// CSES ID: 1197
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,-w});
    }
    //Bellman-Ford
    const long long INF = LLONG_MAX;
    vector<long long> dist(n+1,INF);
    dist[1]=0;
    for(int i=1;i<=n-1;i++){
        for(int u=1;u<=n;u++){
            for(auto [v,w]:adj[u]){
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    bool neg_cycle=false;
    for(int u=1;u<=n;u++){
        for(auto [v,w]:adj[u]){
                if (dist[v] > dist[u] + w) {
                    neg_cycle=true;
                    break;
            }
        }
    }
    if(neg_cycle){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
