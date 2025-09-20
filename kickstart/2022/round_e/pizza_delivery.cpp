#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 11
#define P 10
#define M 21

pii a[N][N];
ll dp[M][(1 << P)][N][N];

int GetXDirection(const int d) {
	if (d == 0) {
		return -1;
	}

	if (d == 1) {
		return 0;
	}

	if (d == 2) {
		return 0;
	}

	if (d == 3) {
		return 1;
	}

	assert(false);
}

int GetYDirection(const int d) {
	if (d == 0) {
		return 0;
	}

	if (d == 1) {
		return 1;
	}

	if (d == 2) {
		return -1;
	}

	if (d == 3) {
		return 0;
	}

	assert(false);
}

ll CalculateNewValue(const ll c, const char op, const int kd) {
	if (op == '+') {
		return c + kd;
	}

	if (op == '-') {
		return c - kd;
	}

	if (op == '*') {
		return c * kd;
	}

	assert(op == '/');

	if (c >= 0) {
		return c / kd;
	}

	return (c / kd) - (c % kd != 0);
}

string Solve() {
	int n, p, m, ar, ac;
	scanf("%d%d%d%d%d", &n, &p, &m, &ar, &ac);

	vector<tuple<int, int, char, int>> directions;
	for (int d = 0; d < 4; ++d) {
		string op;
		int kd;
		cin >> op >> kd;
		directions.push_back({GetXDirection(d), GetYDirection(d), op[0], kd});
	}

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			a[x][y] = {0, 0};
		}
	}

	for (int k = 0; k < p; ++k) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		a[x][y] = {(1 << k), c};
	}

	for (int t = 0; t <= m; ++t) {
		for (int mask = 0; mask < (1 << p); ++mask) {
			for (int x = 1; x <= n; ++x) {
				for (int y = 1; y <= n; ++y) {
					dp[t][mask][x][y] = LLONG_MIN;
				}
			}
		}
	}

	dp[0][0][ar][ac] = 0;

	for (int t = 0; t < m; ++t) {
		const int nt = t + 1;

		for (int mask = 0; mask < (1 << p); ++mask) {
			for (int x = 1; x <= n; ++x) {
				for (int y = 1; y <= n; ++y) {
					if (dp[t][mask][x][y] == LLONG_MIN) {
						continue;
					}

					for (const auto [dx, dy, op, kd] : directions) {
						const int nx = x + dx, ny = y + dy;
						if (nx <= 0 || nx > n || ny <= 0 || ny > n) {
							continue;
						}

						ll new_val = CalculateNewValue(dp[t][mask][x][y], op, kd);
						if (dp[nt][mask][nx][ny] < new_val) {
							dp[nt][mask][nx][ny] = new_val;
						}

						const auto [cell_mask, cell_val] = a[nx][ny];
						if ((mask & cell_mask) == 0) {
							new_val += cell_val;
						}

						const int new_mask = mask | cell_mask;

						if (dp[nt][new_mask][nx][ny] < new_val) {
							dp[nt][new_mask][nx][ny] = new_val;
						}
					}
				}
			}
		}
	}

	ll ans = LLONG_MIN;
	for (int t = 0; t <= m; ++t) {
		for (int x = 1; x <= n; ++x) {
			for (int y = 1; y <= n; ++y) {
				ans = max(ans, dp[t][(1 << p) - 1][x][y]);
			}
		}
	}

	return ans == LLONG_MIN ? "IMPOSSIBLE" : to_string(ans);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}