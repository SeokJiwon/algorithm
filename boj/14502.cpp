#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MAX 8
using namespace std;

int n, m, space, result;
int map[MAX][MAX];
int copy_map[MAX][MAX];
bool flag[MAX * MAX];
bool visit[MAX][MAX];
vector<pair<int, int>> virus, zeros;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) zeros.push_back(make_pair(i, j)); //좌표가 0이면 zeros에 삽입
			if (map[i][j] == 2) virus.push_back(make_pair(i, j)); //좌표가 1이면 virus에 삽입
		}
	}

	space = zeros.size(); 
}

void bfs(int x, int y) {
	//바이러스가 있는 좌표의 위치를 queue에 삽입
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		//바이러스가 있는 좌표 상,하,좌,우로 0인 경우(벽이 아닌 경우) 모두 바이러스를 퍼뜨림!
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!visit[nx][ny] && copy_map[nx][ny] == 0) { //방문하지 않았고 벽이 아닌 경우
				copy_map[nx][ny] = 2; //바이러스를 퍼뜨림
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny)); //바이러스를 퍼뜨린 좌표를 q에 재삽입
			}
		}
	}
}

void spread_virus() {
	int cnt = 0;
	//map을 copy_map에 복사해줌.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	//visit을 전부 false로 초기화
	memset(visit, false, sizeof(visit));
	
	for (int i = 0; i < space; i++) {
		if (cnt == 3) break; //벽 다 세우면 break
		if (flag[i] == true) {
			int x = zeros[i].first;
			int y = zeros[i].second;
			copy_map[x][y] = 1;
			cnt++;
		}
	}

	//바이러스 주변으로 bfs
	for (int i = 0; i < int(virus.size()); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		bfs(x, y);
	}

	//바이러스를 모두 퍼뜨린 이후
	int safe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy_map[i][j] == 0) safe++; //안전한 곳 카운트
		}
	}

	result = (result > safe ? result : safe);
}

void make_wall(int idx, int cnt) {
	if (cnt == 3) { //벽이 다 세워지면 바이러스 퍼뜨림
		spread_virus(); 
		return;
	}

	for (int i = idx; i < space; i++) {
		if (flag[i] == true) continue;
		flag[i] = true;
		make_wall(i, cnt + 1);
		flag[i] = false;
	}
}

int main()
{
    input(); 
    make_wall(0, 0);
    printf("%d", result);
}