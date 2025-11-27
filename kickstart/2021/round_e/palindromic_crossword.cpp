#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000000

int parent[N];
char C[N];

int Find(int i) {
	return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j) {
	i = Find(i), j = Find(j);
	if (i == j) {
		return;
	}

	if (i > j) {
		swap(i, j);
	}

	parent[j] = i;
}

int GetIndex(const int n, const int m, const int x, const int y) {
	return m * x + y;
}

pair<int, vector<string>> Solve() {
	int n, m;
	cin >> n >> m;

	vector<string> A(n);
	for (int x = 0; x < n; ++x) {
		cin >> A[x];
	}

	iota(parent, parent + n * m, 0);

	for (int x = 0; x < n; ++x) {
		for (int y1 = 0; y1 < m; ++y1) {
			if (A[x][y1] == '#') {
				continue;
			}

			int y2 = y1;
			for (; y2 < m && A[x][y2] != '#'; ++y2);
			--y2;

			for (int k = 0; y1 + k < y2 - k; ++k) {
				Union(GetIndex(n, m, x, y1 + k), GetIndex(n, m, x, y2 - k));
			}

			y1 = y2;
		}
	}

	for (int y = 0; y < m; ++y) {
		for (int x1 = 0; x1 < n; ++x1) {
			if (A[x1][y] == '#') {
				continue;
			}

			int x2 = x1;
			for (; x2 < n && A[x2][y] != '#'; ++x2);
			--x2;

			for (int k = 0; x1 + k < x2 - k; ++k) {
				Union(GetIndex(n, m, x1 + k, y), GetIndex(n, m, x2 - k, y));
			}

			x1 = x2;
		}
	}

	fill(C, C + n * m, '.');

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			const char c = A[x][y];
			if (c == '.') {
				continue;
			}
			C[Find(GetIndex(n, m, x, y))] = c;
		}
	}

	vector<string> B(n, string(m, '.'));
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			B[x][y] = C[Find(GetIndex(n, m, x, y))];
		}
	}

	int ans = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			ans += (B[x][y] != A[x][y]);
		}
	}

	return {ans, B};
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		const auto [d, s] = Solve();

		printf("Case #%d: %d\n", k, d);
		for (const auto& si : s) {
			cout << si << '\n';
		}
	}
	return 0;
}