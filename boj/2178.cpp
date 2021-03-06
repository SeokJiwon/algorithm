#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
int arr[101][101]={0,};
int check[101][101]={0,};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    check[x][y]=1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < N && 0 <= ny && ny < M){
                if(check[nx][ny] == 0 && arr[nx][ny] == 1){
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = check[x][y] + 1;
                }
                else if(check[nx][ny] == 0){
                    check[nx][ny] = -1;
                }
            }
        }
    }
}

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    bfs(0,0);

    cout << check[N-1][M-1] << "";
}