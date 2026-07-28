// Edit Distance
// CSES ID: 1639
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin>>a;
    cin>>b;
    int n=a.size(),m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=n-1;i>=0;i--){
        dp[i][m]=1+dp[i+1][m];
    }
    for(int j=m-1;j>=0;j--){
        dp[n][j]=1+dp[n][j+1];
    }

    function<int(char,char)> check=[&](char x,char y){
        if(x==y){
            return 0;
        }
        else{
            return 1;
        }
    };

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            dp[i][j]=min({1+dp[i+1][j],1+dp[i][j+1],check(a[i],b[j])+dp[i+1][j+1]});
        }
    }
    cout<<dp[0][0]<<endl;

    return 0;
}
