#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 12;

int main()
{
	int dp[MAX];
	int N = 0;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}