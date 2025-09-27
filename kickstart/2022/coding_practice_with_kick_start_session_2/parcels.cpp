#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 252

char s[N][N];
int A[N][N];

int CalculateUpperLimit(const int n, const int m) {
	return n + m;
}

bool CheckTrivial(const int n, const int m, const int d) {
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			if (A[x][y] > d) {
				return false;
			}
		}
	}
	return true;
}

bool Check(const int n, const int m, const int d) {
	if (CheckTrivial(n, m, d)) {
		return true;
	}

	int min_x_plus_y = n + m, max_x_plus_y = 0;
	int min_x_minus_y = n, max_x_minus_y = -m;

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			if (A[x][y] <= d) {
				continue;
			}

			const int x_plus_y = x + y, x_minus_y = x - y;

			min_x_plus_y = min(min_x_plus_y, x_plus_y);
			max_x_plus_y = max(max_x_plus_y, x_plus_y);

			min_x_minus_y = min(min_x_minus_y, x_minus_y);
			max_x_minus_y = max(max_x_minus_y, x_minus_y);
		}
	}

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			const int x_plus_y = x + y, x_minus_y = x - y;
			if (max(max(abs(x_plus_y - min_x_plus_y), abs(max_x_plus_y - x_plus_y)), max(abs(x_minus_y - min_x_minus_y), abs(max_x_minus_y - x_minus_y))) <= d) {
				return true;
			}
		}
	}

	return false;
}

int Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int x = 0; x < n; ++x) {
		scanf("%s", s[x]);
	}

	for (int x = 0; x <= n + 1; ++x) {
		for (int y = 0; y <= m + 1; ++y) {
			A[x][y] = n + m;
		}
	}

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			if (s[x - 1][y - 1] == '1') {
				A[x][y] = 0;
			}
		}
	}

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			A[x][y] = min(A[x][y], 1 + A[x][y - 1]);
		}

		for (int y = m; y > 0; --y) {
			A[x][y] = min(A[x][y], 1 + A[x][y + 1]);
		}
	}

	for (int y = 1; y <= m; ++y) {
		for (int x = 1; x <= n; ++x) {
			A[x][y] = min(A[x][y], 1 + A[x - 1][y]);
		}

		for (int x = n; x > 0; --x) {
			A[x][y] = min(A[x][y], 1 + A[x + 1][y]);
		}
	}

	// for (int x = 1; x <= n; ++x) {
	// 	for (int y = 1; y <= m; ++y) {
	// 		printf("%d ", A[x][y]);
	// 	}
	// 	printf("\n");
	// }

	int ans = n + m;
	for (int l = 0, r = CalculateUpperLimit(n, m); l <= r;) {
		const int mid = l + (r - l) / 2;
		if (Check(n, m, mid)) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
		// printf("l = %d r = %d mid = %d ans = %d\n", l, r, mid, ans);
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}