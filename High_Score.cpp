// High Score
// CSES ID: 1673
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<int>> rev(n + 1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,-w});
        rev[v].push_back(u);
    }
    //Bellman-Ford
    const long long INF = 4e18;
    vector<long long> dist(n+1,INF);
    dist[1]=0;
    for(int i=1;i<=n-1;i++){
        for(int u=1;u<=n;u++){
            for(auto [v,w]:adj[u]){
                if (dist[u] != INF && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    vector<bool> bad(n + 1, false);
    for (int u = 1; u <= n; u++) {
        if (dist[u] == INF) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                bad[v] = true;
            }
        }
    }
    vector<bool> reachable(n + 1, false);

    queue<int> q;
    q.push(n);
    reachable[n] = true;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        for (int v : rev[u]) {

            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {

        if (bad[i] && reachable[i]) {

            cout << -1 << '\n';
            return 0;
        }
    }

    cout << -dist[n] << '\n';

    return 0;
}
