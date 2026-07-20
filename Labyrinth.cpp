// Labyrinth
// CSES ID: 1193
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<string> grid(n, string(m, ' '));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    //BFS finds shortest path in equal weight graph
    vector<string> path;
    int dx[]={0,-1,0,1};
    int dy[]={-1,0,1,0};
    char dir[]={'L','U','R','D'};
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));
    vector<vector<char>> parent_dir(n,vector<char>(m,'.'));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (grid[i][j]=='A'){
                //start BFS
                queue<pair<int,int>> q;
                visited[i][j] = true;
                q.push({i,j});
                while(!q.empty()){
                    auto [x,y]=q.front();
                    if (grid[x][y]=='B'){
                        break;
                    }
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if (nx >= 0 && nx < n &&
                            ny >= 0 && ny < m &&
                            !visited[nx][ny] &&
                            grid[nx][ny] != '#'){
                                q.push({nx,ny});
                                visited[nx][ny]=true;
                                parent_dir[nx][ny]=dir[k];
                                parent[nx][ny]={x,y};
                        }
                    }
                }

            }
        }
    }
    int idx,idy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (grid[i][j]=='B'){
                idx=i;
                idy=j;
                break;
            }
        }
    }

    if (parent_dir[idx][idy]=='.'){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        string ans;

        while (grid[idx][idy] != 'A') {
            ans.push_back(parent_dir[idx][idy]);

            auto [px, py] = parent[idx][idy];
            idx = px;
            idy = py;
        }

        reverse(ans.begin(), ans.end());

        cout << ans.size() << '\n';
        cout << ans << '\n';
        
    }

    return 0;
}
