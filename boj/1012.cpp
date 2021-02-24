#include <iostream>
#include <algorithm>

using namespace std;
 
int m, n, k;
int arr[60][60];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
 
void init()
{
	for (int i = 0; i < 60; ++i) {
		for (int j = 0; j < 60; ++j) {
			arr[i][j] = 0;
		}
	}
}
 
void dfs(int a, int b)
{
	if (arr[a][b] == 1) {
		arr[a][b] = 0;
		for (int l = 0; l < 4; ++l) {
			int x = dx[l] + a;
			int y = dy[l] + b;
			if (x >= 0 && y >= 0 && x < m && y < n) {
				dfs(x, y);
			}
		}
	}
}
 
int main(){	
	int a, b;
	int count;
	int testcase;
 
	cin >> testcase;
 
	while (testcase--) {
		init();
		count = 0;
		cin >> m >> n;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> a >> b;
			arr[a][b] = 1;
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (arr[i][j] == 1) {
					dfs(i, j);
					++count;
				}
			}
		}
		cout << count << " ";
	}
}