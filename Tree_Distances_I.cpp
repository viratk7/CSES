// Tree Distances I
// CSES ID: 1132
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

    vector<int> d1(n+1,0);
    vector<bool> visited(n+1,false);
    d1[1]=0;
    visited[1]=true;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr_node=q.front();
        q.pop();
        for(int child:tree[curr_node]){
            if(!visited[child]){    
                q.push(child);
                visited[child]=true;
                d1[child]=d1[curr_node]+1;
            }
        }
    }
    
    int u1,max_d1=0;
    for(int i=1;i<=n;i++){
        if(d1[i]>max_d1){
            max_d1=d1[i];
            u1=i;
        }
    }
    //bfs from u1
    vector<int> d2(n+1,0);
    vector<bool> visited2(n+1,false);
    visited2[u1]=true;
    d2[u1]=0;
    queue<int> q_;
    q_.push(u1);
    while(!q_.empty()){
        int curr_node=q_.front();
        q_.pop();
        for(int child:tree[curr_node]){
            if(!visited2[child]){    
                q_.push(child);
                visited2[child]=true;
                d2[child]=d2[curr_node]+1;
            }
        }
    }

    int u2,max_d2=0;
    for(int i=1;i<=n;i++){
        if(d2[i]>max_d2){
            max_d2=d2[i];
            u2=i;
        }
    }
    //bfs from u2
    vector<int> d3(n+1,0);
    vector<bool> visited3(n+1,false);
    visited3[u2]=true;
    d3[u2]=0;
    queue<int> q__;
    q__.push(u2);
    while(!q__.empty()){
        int curr_node=q__.front();
        q__.pop();
        for(int child:tree[curr_node]){
            if(!visited3[child]){    
                q__.push(child);
                visited3[child]=true;
                d3[child]=d3[curr_node]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<max(d2[i],d3[i])<<" ";
    }
    return 0;
}

