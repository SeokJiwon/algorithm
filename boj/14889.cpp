#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[21][21];
bool visit[21];
int ans = 1000000000;
	
void minScore(int start, int cnt) {
	if (cnt == N / 2) {
		int start=0, link=0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (visit[i] && visit[j]) start += arr[i][j];
				if (!visit[i] && !visit[j]) link += arr[i][j];
			}
		}
		int a = abs(start - link);
		if (ans > a) {
			ans = a;
		}
		return;
	}
	for (int i = start; i < N; ++i) {
		visit[i] = true;
		minScore(i + 1, cnt + 1);
		visit[i] = 0;
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> arr[i][j];
		}
	}
	minScore(1,0 );
	cout << ans << "\n";
	return 0;
}