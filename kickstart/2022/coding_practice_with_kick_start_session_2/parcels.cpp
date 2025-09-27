#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 252

char s[N][N];
int A[N][N], B[N][N], C[N][N];

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

void Copy(const int n, const int m) {
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			C[x][y] = max(C[x][y], B[x][y]);
		}
	}
}

bool Check(const int n, const int m, const int d) {
	if (CheckTrivial(n, m, d)) {
		return true;
	}

	for (int x = 0; x <= n + 1; ++x) {
		for (int y = 0; y <= m + 1; ++y) {
			B[x][y] = INT_MIN;
			C[x][y] = INT_MIN;
		}
	}

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			B[x][y] = max(A[x][y] > d ? 0 : INT_MIN, 1 + max(B[x][y - 1], B[x - 1][y]));
		}
	}
	Copy(n, m);

	for (int x = 1; x <= n; ++x) {
		for (int y = m; y > 0; --y) {
			B[x][y] = max(A[x][y] > d ? 0 : INT_MIN, 1 + max(B[x][y + 1], B[x - 1][y]));
		}
	}
	Copy(n, m);

	for (int x = n; x > 0; --x) {
		for (int y = 1; y <= m; ++y) {
			B[x][y] = max(A[x][y] > d ? 0 : INT_MIN, 1 + max(B[x][y - 1], B[x + 1][y]));
		}
	}
	Copy(n, m);

	for (int x = n; x > 0; --x) {
		for (int y = m; y > 0; --y) {
			B[x][y] = max(A[x][y] > d ? 0 : INT_MIN, 1 + max(B[x][y + 1], B[x + 1][y]));
		}
	}
	Copy(n, m);

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			if (C[x][y] <= d) {
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