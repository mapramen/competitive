#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pii> ReadInputs() {
	vector<pii> v;
	for (int x, y; scanf("%d,%d", &x, &y) != EOF; v.push_back({y, x}));
	return v;
}

void Dedup(vector<int>& v) {
	v.push_back(INT_MIN);
	v.push_back(INT_MAX);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

int GetCompressedValue(const vector<int>& v, const int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

pair<vector<int>, vector<int>> CoordinateCompress(vector<pii>& pts) {
	vector<int> X, Y;

	for (const auto [x, y] : pts) {
		X.push_back(x);
		Y.push_back(y);
	}

	Dedup(X);
	Dedup(Y);

	for (pii& p : pts) {
		p = {GetCompressedValue(X, p.first), GetCompressedValue(Y, p.second)};
	}

	return {X, Y};
}

void DFS(vector<vector<int>>& s, const int x, const int y) {
	if (x < 0 || x >= s.size() || y < 0 || y >= s.front().size() || s[x][y] != 2) {
		return;
	}

	s[x][y] = 0;
	DFS(s, x - 1, y);
	DFS(s, x, y - 1);
	DFS(s, x, y + 1);
	DFS(s, x + 1, y);
}

void Print(const vector<vector<int>>& s) {
	const int n = s.size(), m = s.front().size();

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			printf("%d", s[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	auto pts = ReadInputs();
	const auto [X, Y] = CoordinateCompress(pts);

	const int n = X.size(), m = Y.size(), k = pts.size();

	vector<vector<int>> s(n, vector<int>(m, 2));

	for (int i = 0; i < k; ++i) {
		const int j = (i + 1) % k;

		const auto [x1, y1] = pts[i];
		const auto [x2, y2] = pts[j];

		// printf("(%d,%d) => (%d,%d)\n", x1, y1, x2, y2);

		if (x1 == x2) {
			for (int y = min(y1, y2); y <= max(y1, y2); ++y) {
				s[x1][y] = 1;
			}
		} else {
			for (int x = min(x1, x2); x <= max(x1, x2); ++x) {
				s[x][y1] = 1;
			}
		}
	}

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
				DFS(s, x, y);
			}
		}
	}

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			s[x][y] = min(1, s[x][y]);
		}
	}

	// Print(s);

	for (int x = 1; x < n; ++x) {
		for (int y = 1; y < m; ++y) {
			s[x][y] += (s[x - 1][y] + s[x][y - 1] - s[x - 1][y - 1]);
		}
	}

	ll ans = 1;
	for (int i = 0; i < k; ++i) {
		for (int j = i + 1; j < k; ++j) {
			auto [x1, y1] = pts[i];
			auto [x2, y2] = pts[j];

			if (x2 < x1) {
				swap(x1, x2);
			}

			if (y2 < y1) {
				swap(y1, y2);
			}

			const int expected_cnt = 1ll * (x2 - x1 + 1) * (y2 - y1 + 1);
			const int actual_cnt = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];

			if (actual_cnt != expected_cnt) {
				continue;
			}

			ans = max(ans, 1ll * (X[x2] - X[x1] + 1) * (Y[y2] - Y[y1] + 1));
		}
	}
	cout << ans << '\n';

	return 0;
}