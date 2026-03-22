#include <bits/stdc++.h>
using namespace std;

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n < 4) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	if (n == 4) {
		cout << "1 1 3 2\n";
		cout << "2 1 2 4\n";
		cout << "3 3 3 4\n";
		cout << "2 1 4 4\n";
		return 0;
	}

	// Initial grid: row i filled with i+1
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = i + 1;
		}
	}

	vector<int> rowSum(n, 0), colSum(n, 0);

	// Initialize sums
	for (int i = 0; i < n; i++) {
		rowSum[i] = (i + 1) * n;
	}
	for (int j = 0; j < n; j++) {
		colSum[j] = n * (n + 1) / 2;
	}

	// Frequency map for sums
	unordered_map<int, int> freq;

	auto add = [&](int x, int& distinct) {
		if (freq[x] == 0) distinct++;
		freq[x]++;
	};

	auto remove = [&](int x, int& distinct) {
		freq[x]--;
		if (freq[x] == 0) distinct--;
	};

	int distinct = 0;

	// Initialize distinct count
	for (int i = 0; i < n; i++) add(rowSum[i], distinct);
	for (int j = 0; j < n; j++) add(colSum[j], distinct);

	int target = 2 * n;

	// Try random swaps
	for (int iter = 0; iter < 1000000; iter++) {
		if (distinct == target) break;

		int r1 = rng() % n;
		int c1 = rng() % n;
		int r2 = rng() % n;
		int c2 = rng() % n;

		if (r1 == r2 && c1 == c2) continue;

		int v1 = a[r1][c1];
		int v2 = a[r2][c2];

		if (v1 == v2) continue;

		int prevDistinct = distinct;

		// Remove old sums
		remove(rowSum[r1], distinct);
		remove(rowSum[r2], distinct);
		remove(colSum[c1], distinct);
		remove(colSum[c2], distinct);

		// Apply swap effect
		rowSum[r1] += v2 - v1;
		rowSum[r2] += v1 - v2;
		colSum[c1] += v2 - v1;
		colSum[c2] += v1 - v2;

		// Add new sums
		add(rowSum[r1], distinct);
		add(rowSum[r2], distinct);
		add(colSum[c1], distinct);
		add(colSum[c2], distinct);

		// Accept only if improved
		if (distinct <= prevDistinct) {
			// Revert

			remove(rowSum[r1], distinct);
			remove(rowSum[r2], distinct);
			remove(colSum[c1], distinct);
			remove(colSum[c2], distinct);

			rowSum[r1] += v1 - v2;
			rowSum[r2] += v2 - v1;
			colSum[c1] += v1 - v2;
			colSum[c2] += v2 - v1;

			add(rowSum[r1], distinct);
			add(rowSum[r2], distinct);
			add(colSum[c1], distinct);
			add(colSum[c2], distinct);
		} else {
			// Keep swap
			swap(a[r1][c1], a[r2][c2]);
		}
	}

	// Output result
	if (distinct != target) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}