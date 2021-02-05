#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int N, M, answer;
int map[500][500];
int visited[500][500];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void sum(int x, int y) {
	// o o
	// o o
	if (y + 1 < M && x + 1 < N) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 1]);
	}

	// o o o o
	if (y + 3 < M) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x][y + 3]);
	}

	// o
	// o
	// o
	// o
	if (x + 3 < N) {
		answer = max(answer, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 3][y]);
	}

	// o
	// o
	// o o
	if (y + 1 < M && x + 2 < N) {
		answer = max(answer, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 2][y + 1]);
	}

	//   o
	//   o
	// o o
	if (y + 1 < M && x + 2 < N) {
		answer = max(answer, map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y] + map[x + 2][y + 1]);
	}

	// o o o
	// o
	if (y + 2 < M && x + 1 < N) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y]);
	}

	// o
	// o o o
	if (y + 2 < M && x + 1 < N) {
		answer = max(answer, map[x][y] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	}

	// o o
	//   o
	//   o
	if (y + 1 < M && x + 2 < N) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1]);
	}

	// o o
	// o
	// o
	if (y + 1 < M && x + 2 < N) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 2][y]);
	}

	//     o
	// o o o
	if (y + 2 < M && x + 1 < N) {
		answer = max(answer, map[x][y + 2] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	}

	// o o o
	//     o
	if (y + 2 < M && x + 1 < N) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 2]);
	}

	// o
	// o o
	//   o
	if (y + 1 < M && x + 2 < N) {
		answer = max(answer, map[x][y] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 2][y + 1]);
	}

	//   o
	// o o
	// o
	if (y + 1 < M && x + 2 < N) {
		answer = max(answer, map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 2][y]);
	}

	//   o o
	// o o
	if (y + 2 < M && x + 1 < N) {
		answer = max(answer, map[x + 1][y] + map[x + 1][y + 1] + map[x][y + 1] + map[x][y + 2]);
	}

	// o o
	//   o o
	if (y + 2 < M && x + 1 < N) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	}

	//   o
	// o o o
	if (y + 2 < M && x + 1 < N) {
		answer = max(answer, map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	}

	// o o o
	//   o
	if (y + 2 < M && x + 1 < N) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
	}

	//   o
	// o o
	//   o
	if (y + 1 < M && x + 2 < N) {
		answer = max(answer, map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1]);
	}
	// o
	// o o
	// o
	if (y + 1 < M && x + 2 < N) {
		answer = max(answer, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum(i, j);
		}
	}

	cout << answer;
}