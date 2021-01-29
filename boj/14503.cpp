#include <iostream>
#define MAX_SIZE 50
using namespace std;
 
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int n, m;
int map[MAX_SIZE][MAX_SIZE];  // 1==벽, 2==청소
 
int next_dir(int d) {
    return (d + 1) % 4;
}
 
bool map_impossible(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 1;
    return 0;
}
 
int main() {
    int r, c, d;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
 
    int x = c, y = r;
 
    if (d == 1) d = 3;
    else if (d == 3) d = 1;
 
    int res = 0;
    while (true) {
        if (map[y][x] == 0) {
            map[y][x] = 2;
            res++;
        }
        bool search_flag = false;
        for (int i = 0; i < 4; i++) {
            d = next_dir(d);
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (map_impossible(nx, ny) || map[ny][nx] != 0) 
                continue;
            x = nx;
            y = ny;
            search_flag = true;
            break;
        }
 
        if (search_flag) 
            continue;
 
        // 4방향 모두 못찾았을 때
         d = next_dir(d + 1);    // 뒷 방향
        int nx = x + dx[d];
        int ny = y + dy[d];
 
        if (map_impossible(nx, ny) || map[ny][nx] == 1) 
            break;
        // 뒤가 벽이 아니면 
        d = next_dir(d + 1);    // 방향 유지
        x = nx;                 // 뒤로 가기
        y = ny;
    }
    printf("%d", res);
}