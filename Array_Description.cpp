// Array Description
// CSES ID: 1746

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> memo(n, vector<int>(m + 1, -1));

    function<int(int,int)> dp = [&](int i, int prev) {

        if (i == n)
            return 1;

        if (memo[i][prev] != -1)
            return memo[i][prev];

        long long ans = 0;

        if (arr[i] != 0) {

            if (abs(arr[i] - prev) <= 1)
                ans = dp(i + 1, arr[i]);

        } else {

            for (int nxt = max(1, prev - 1);
                 nxt <= min(m, prev + 1);
                 nxt++) {

                ans = (ans + dp(i + 1, nxt)) % MOD;
            }
        }

        return memo[i][prev] = ans;
    };

    long long ans = 0;

    if (arr[0] == 0) {

        for (int first = 1; first <= m; first++)
            ans = (ans + dp(1, first)) % MOD;

    } else {

        ans = dp(1, arr[0]);
    }

    cout << ans << '\n';
}