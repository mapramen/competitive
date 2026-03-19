#include <bits/stdc++.h>

using namespace std;

#define M 2
#define MOD 1000000007

int A[M][M], B[M][M], D[M][M];

void MatrixMultiply(int A[M][M], int B[M][M], int C[M][M]) {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			int ans = 0;
			for (int k = 0; k < M; ++k) {
				ans = (ans + 1LL * A[i][k] * B[k][j]) % MOD;
			}
			D[i][j] = ans;
		}
	}

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			C[i][j] = D[i][j];
		}
	}
}

int CalculateCount(int n, const int k) {
	A[0][0] = 1, A[0][1] = k, A[1][0] = 1, A[1][1] = 0;
	B[0][0] = 1, B[0][1] = 0, B[1][0] = 0, B[1][1] = 1;

	for (--n; n > 0; n >>= 1) {
		if (n & 1) {
			MatrixMultiply(B, A, B);
		}
		MatrixMultiply(A, A, A);
	}

	return (1ll * B[0][0] * (k + 1) + B[0][1]) % MOD;
}

int Calculate(const int n, int m) {
	int ans = 1;
	for (int i = 2; i * i <= m; ++i) {
		if (m % i != 0) {
			continue;
		}

		int count = 0;
		while (m % i == 0) {
			m /= i;
			++count;
		}

		ans = (1ll * ans * CalculateCount(n, count)) % MOD;
	}

	if (m > 1) {
		ans = (1ll * ans * CalculateCount(n, 1)) % MOD;
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", Calculate(n, m));
	}

	return 0;
}