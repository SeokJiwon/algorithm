#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n, cnt = 1;
int ans = 1000000;
int arr[105][105];
int visited[101][101];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
queue<pair<int,int> > q;

bool safe(int y, int x){
    return y >= 1 && y <= n && x >= 1 && x <= n;
}

void dfs(int y, int x){
    arr[y][x] = cnt;
    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(safe(ny,nx) && arr[ny][nx] == 1)
            dfs(ny,nx);
    }
    return;
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>arr[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!arr[i][j]) continue;
            if(arr[i][j] == 1){
                cnt++;
                dfs(i,j);
            }
        }
    }

    for(int k=2; k<=cnt; k++){
        while(!q.empty()) q.pop();
        memset(visited,-1,sizeof(visited));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j] != k) continue;
                visited[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }

        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if(arr[y][x] && arr[y][x] != k){
                ans = min(ans,visited[y][x]);
                break;
            }

            for(int i=0; i<4; i++){
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];
                if(safe(ny,nx) && visited[ny][nx] == -1){
                    visited[ny][nx] = visited[y][x]+1;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
    cout<<ans-1;
}