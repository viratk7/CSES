// Monsters
// CSES ID: 1194
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<vector<int>> time(n,vector<int>(m,-1));
    //run bfs for all monster nodes
    queue<vector<int>> q;
    queue<vector<int>> q_;
    int sx, sy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M'){
                vector<int> temp={i,j,0};
                q.push(temp);
                time[i][j]=0;                
            }
            else if(grid[i][j]=='A'){
                sx = i;
                sy = j;
                vector<int> temp={i,j,0};
                q_.push(temp);
                visited[i][j]=true;
            }
        }
    }
    if (sx == 0 || sx == n-1 || sy == 0 || sy == m-1) {
        cout << "YES\n";
        cout << 0 << "\n\n";
        return 0;
    }
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    while(!q.empty()){
        vector<int> curr=q.front();
        q.pop();
        int x=curr[0],y=curr[1],t=curr[2];
        for(int k=0;k<4;k++){
            int nx=x+dx[k],ny=y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && time[nx][ny]==-1 && grid[nx][ny]!='#'){
                time[nx][ny]=t+1;
                vector<int> temp={nx,ny,t+1};
                q.push(temp);
            }
        }
    }
    //bfs for node
    bool valid=false;
    pair<int,int> coord;
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    while(!q_.empty()){
        vector<int> curr=q_.front();
        q_.pop();
        int x=curr[0],y=curr[1],t=curr[2];
        if(x == 0 || x == n-1 || y == 0 || y == m-1){
            valid=true;
            coord={x,y};
        }
        for(int k=0;k<4;k++){
            int nx=x+dx[k],ny=y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && grid[nx][ny]!='#'){
                if(time[nx][ny]==-1 || time[nx][ny]>t+1){
                    if(nx == 0 || nx == n-1 || ny == 0 || ny == m-1){
                        valid=true;
                        coord={nx,ny};
                    }
                    visited[nx][ny]=true;
                    parent[nx][ny]={x,y};
                    vector<int> temp={nx,ny,t+1};
                    q_.push(temp);
                    if(valid){
                        break;
                    }
                }
            }
            if(valid){
                break;
            }
        }
    }
    
    if(!valid){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        //build the path from corner
        string path;
        int x=coord.first,y=coord.second;
        while (x!=-1 && y!=-1){
            auto [px, py] = parent[x][y];

            if (x == px + 1) path += 'D';
            else if (x == px - 1) path += 'U';
            else if (y == py + 1) path += 'R';
            else if (y == py - 1) path += 'L';

            x = px;
            y = py;
        }
        reverse(path.begin(),path.end());
        cout<<path.length()<<endl;
        cout<<path<<endl;
    }

    return 0;
}
