#include <bits/stdc++.h>

using namespace std;

#define N 501
#define LOGN 9

char s[N];
int T[LOGN][LOGN][N][N];

int Query(const int x1, const int y1, const int x2, const int y2) {
	const int kx = __lg(x2 - x1 + 1);
	const int ky = __lg(y2 - y1 + 1);
	return T[kx][ky][x2][y2] | T[kx][ky][x1 + (1 << kx) - 1][y2] | T[kx][ky][x2][y1 + (1 << ky) - 1] | T[kx][ky][x1 + (1 << kx) - 1][y1 + (1 << ky) - 1];
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int x = 1; x <= n; ++x) {
		scanf("%s", s);

		for (int y = 1; y <= n; ++y) {
			T[0][0][x][y] = 1 << (s[y - 1] - 'A');
		}
	}

	for (int i = 0; i < LOGN; ++i) {
		if (i != 0) {
			for (int x = (1 << i); x <= n; ++x) {
				for (int y = 1; y <= n; ++y) {
					T[i][0][x][y] = T[i - 1][0][x][y] | T[i - 1][0][x - (1 << (i - 1))][y];
				}
			}
		}

		for (int j = 1; j < LOGN; ++j) {
			for (int x = 1; x <= n; ++x) {
				for (int y = (1 << j); y <= n; ++y) {
					T[i][j][x][y] = T[i][j - 1][x][y] | T[i][j - 1][x][y - (1 << (j - 1))];
				}
			}
		}
	}

	const int all_set = (1 << k) - 1;
	long long ans = 0;
	for (int x1 = 1; x1 <= n; ++x1) {
		for (int x2 = x1; x2 <= n; ++x2) {
			for (int y1 = 1, y2 = 1; y2 <= n; ++y2) {
				for (; y1 <= y2 && Query(x1, y1, x2, y2) == all_set; ++y1);
				ans += y1 - 1;
			}
		}
	}
	printf("%lld\n", ans);

	return 0;
}