#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pii> moves = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};

int GetIndex(int n, int m, int x, int y) {
	return x * m + y;
}

string Solve(int n, int m, string& path, int mask, int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || (mask & (1 << GetIndex(n, m, x, y))) != 0) {
		return "";
	}

	path.push_back('A' + y);
	path.push_back('1' + x);

	mask |= (1 << GetIndex(n, m, x, y));

	if (mask == (1 << (n * m)) - 1) {
		return path;
	}

	for (auto [dx, dy] : moves) {
		string res = Solve(n, m, path, mask, x + dx, y + dy);
		if (!res.empty()) {
			return res;
		}
	}

	path.pop_back();
	path.pop_back();

	return "";
}

string Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) {
			string path = "";
			int mask = 0;
			string res = Solve(n, m, path, mask, x, y);
			if (!res.empty()) {
				return res;
			}
		}
	}

	return "-1";
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%s\n", Solve().c_str());
	}
	return 0;
}