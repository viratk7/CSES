// Company Queries I
// CSES ID: 1687
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;
    int LOG=20;
    vector<int> parent(n+1,0);
    vector<vector<int>> up(n+1,vector<int>(LOG,-1));

    for(int i=2;i<=n;i++){
        cin>>parent[i];
        up[i][0]=parent[i];
    }

    //Fill in the up table
    for(int i=1;i<LOG;i++){
        for(int node=2;node<=n;node++){
            if (up[node][i-1] != -1){
                up[node][i]=up[up[node][i-1]][i-1];
            }
        }
    }
    //Every number can be written in power of 2
    //use bitwise of k
    while(q--){
        int x,k;
        cin>>x>>k;
        int ancestor=x;
        for(int j=0;j<LOG;j++){
            if(k & (1<<j)){
                ancestor=up[ancestor][j];
            }
            if(ancestor == -1){
                break;
            }
        }
        cout<<ancestor<<endl;
    }

    return 0;
}
