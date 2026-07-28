// Book Shop
// CSES ID: 1158

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);

    for (int i = 0; i < n; i++)
        cin >> h[i];

    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<vector<int>> dp(n+1, vector<int>(x + 1, 0));

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=x;j++){
            dp[i][j]=dp[i+1][j];
            if (j-h[i]>=0){
                dp[i][j]=max(dp[i+1][j],s[i]+dp[i+1][j-h[i]]);
            }
        }
    }

    cout << dp[0][x] << '\n';

    return 0;
}