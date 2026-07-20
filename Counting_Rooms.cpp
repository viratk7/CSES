#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == '.' && !visited[i][j]) {

                ans++;

                stack<pair<int,int>> st;
                st.push({i, j});
                visited[i][j] = true;

                while (!st.empty()) {

                    auto [x, y] = st.top();
                    st.pop();

                    for (int k = 0; k < 4; k++) {

                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < n &&
                            ny >= 0 && ny < m &&
                            !visited[nx][ny] &&
                            grid[nx][ny] == '.') {

                            visited[nx][ny] = true;
                            st.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}