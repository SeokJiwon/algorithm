#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int dp[501][501] = { 0, };
	int triangle[501][501] = { 0, };
	int N;
	cin >> N;
	cin >> triangle[1][1];
	dp[1][1] = triangle[1][1];

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cin >> triangle[i][j];
			dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
		}
	}
	for (int i = 1; i <= N; ++i)
		dp[N][0] = max(dp[N][0], dp[N][i]);
	
	cout << dp[N][0];
}