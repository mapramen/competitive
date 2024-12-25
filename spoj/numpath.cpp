#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 50

int c[N][N];

void Initialize() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			c[i][j] = 0;
		}
	}

	for (int i = 0; i < N; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
}

int Solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	return c[n - 1 + m - 1][n - 1];
}

int main() {
	Initialize();

	int t;
	scanf("%d", &t);

	while (t--) {
		printf("%d\n", Solve());
	}

	return 0;
}