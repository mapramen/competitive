#include <bitset>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

int main() {
	// Optimize standard I/O operations for performance
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	if (!(cin >> n)) return 0;

	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	// Parity Check: If sum is odd, we can never reach 0
	if (sum % 2 != 0) {
		cout << -1 << "\n";
		return 0;
	}

	int target = sum / 2;

	// DP using bitset for O(N * Target / 64) fast execution
	// Memory is about 62.5 MB, which easily fits standard limits
	vector<bitset<500005>> dp(n + 1);
	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		dp[i + 1] = dp[i] | (dp[i] << a[i]);
	}

	// Partition check
	if (!dp[n][target]) {
		cout << -1 << "\n";
		return 0;
	}

	// Backtrack to divide into two sets
	priority_queue<int> pqA, pqB;
	int curr = target;
	for (int i = n - 1; i >= 0; i--) {
		if (curr >= a[i] && dp[i][curr - a[i]]) {
			pqA.push(a[i]);
			curr -= a[i];
		} else {
			pqB.push(a[i]);
		}
	}

	// Perform n-1 operations
	for (int i = 0; i < n - 1; i++) {
		if (!pqA.empty() && !pqB.empty()) {
			int x = pqA.top();
			pqA.pop();
			int y = pqB.top();
			pqB.pop();
			cout << x << " " << y << "\n";

			if (x > y)
				pqA.push(x - y);
			else
				pqB.push(y - x);

		} else if (pqB.empty()) {
			// If B is empty, A can only contain zeroes
			int x = pqA.top();
			pqA.pop();
			int y = pqA.top();
			pqA.pop();
			cout << x << " " << y << "\n";
			pqA.push(abs(x - y));

		} else {
			// If A is empty, B can only contain zeroes
			int x = pqB.top();
			pqB.pop();
			int y = pqB.top();
			pqB.pop();
			cout << x << " " << y << "\n";
			pqB.push(abs(x - y));
		}
	}

	return 0;
}