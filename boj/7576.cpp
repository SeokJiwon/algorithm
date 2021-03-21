#include <iostream>
#include <queue>
using namespace std;
 
int tomato[1001][1001];
int M, N;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int, int>> q;

void bfs(void){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            if(tomato[nx][ny] == 0){
                tomato[nx][ny] = tomato[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
 
int main() {
    cin >> M >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> tomato[i][j];
            if(tomato[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }
    
    bfs();
    
    int answer = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(tomato[i][j] == 0){
                cout << "-1" << '\n';
                return 0;
            }
            
            if(answer < tomato[i][j])
                answer = tomato[i][j];
        }
    }
    cout << answer - 1 << '\n';
    
    return 0;
}