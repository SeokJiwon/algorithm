#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	long long min = 0, max = 0, mid = 0, res = 0;
	vector<long long> trees(n);
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		if (max < trees[i])
			max = trees[i];
	}
	while (min <= max) {
		mid = (min + max) / 2;
		long long p = 0;
		for (long long i : trees)
			if (i - mid > 0)
				p += i - mid;

		if (p >= m) {
			if (res < mid)
				res = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	cout << res << '\n';
}