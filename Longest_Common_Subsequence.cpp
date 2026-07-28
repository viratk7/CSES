// Longest Common Subsequence
// CSES ID: 3403
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        b.push_back(temp);
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    function<int(int,int)> check=[&](int x,int y){
        if(x==y){
            return 1;
        }
        else{
            return 0;
        }
    };

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            dp[i][j]=max({dp[i+1][j],dp[i][j+1],check(a[i],b[j])+dp[i+1][j+1]});
        }
    }
    cout<<dp[0][0]<<endl;


    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] == b[j] &&
            dp[i][j] == 1 + dp[i+1][j+1]) {

            cout<<a[i]<<" ";
            i++;
            j++;
        }
        else if (dp[i][j] == dp[i+1][j]) {
            i++;
        }
        else {
            j++;
        }
    }
    

    return 0;
}
