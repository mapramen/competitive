#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define K 2
#define N 200001
#define LOGN 19
#define MOD 1000000007
#define MOD_INV 142857001

int d[N], dp[N];
int ancestor[LOGN][N];
int prob[LOGN][N][K][K];
int A[K][K], B[K][K], T[K][K];

void FillIdentityMatrix(int A[K][K]) {
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			A[i][j] = 0;
		}
		A[i][i] = 1;
	}
}

void FillProbabilityMatrix(int A[K][K], const int a, const int b) {
	A[0][0] = a;
	A[0][1] = (MOD + 1 - a) % MOD;
	A[1][0] = b;
	A[1][1] = (MOD + 1 - b) % MOD;
}

void Reset(const int n) {
	const int logn = 2 + __lg(n);
	for (int k = 0; k < logn; ++k) {
		ancestor[k][0] = 0;
		FillIdentityMatrix(prob[k][0]);
	}

	ancestor[0][1] = 0;
	FillIdentityMatrix(prob[0][1]);
}

void MatrixMultiply(const int A[K][K], const int B[K][K], int C[K][K]) {
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			int ans = 0;
			for (int k = 0; k < K; ++k) {
				ans = (ans + 1ll * A[i][k] * B[k][j]) % MOD;
			}
			T[i][j] = ans;
		}
	}

	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			C[i][j] = T[i][j];
		}
	}
}

int Query(int i, int j) {
	if (d[j] < d[i]) {
		swap(i, j);
	}

	const int logn = 2 + __lg(d[j]);

	FillIdentityMatrix(B);
	for (int k = logn - 1, x = d[j] - d[i]; k > -1 && x > 0; --k) {
		if ((1 << k) > x) {
			continue;
		}

		MatrixMultiply(prob[k][j], B, B);
		j = ancestor[k][j];
		x ^= (1 << k);
	}

	if (j == i) {
		return (1ll * dp[i] * B[0][0]) % MOD;
	}

	FillIdentityMatrix(A);
	for (int k = logn - 1; k > -1; --k) {
		if (ancestor[k][i] == ancestor[k][j]) {
			continue;
		}

		MatrixMultiply(prob[k][i], A, A);
		MatrixMultiply(prob[k][j], B, B);

		i = ancestor[k][i];
		j = ancestor[k][j];
	}

	MatrixMultiply(prob[0][i], A, A);
	MatrixMultiply(prob[0][j], B, B);

	const int lca = ancestor[0][i];
	const int p = (1ll * A[0][0] * B[0][0]) % MOD, q = (1ll * A[1][0] * B[1][0]) % MOD;
	return (1ll * p * dp[lca] + 1ll * q * (MOD + 1 - dp[lca])) % MOD;
}

vector<int> Solve() {
	int n, q, k;
	scanf("%d%d%d", &n, &q, &k);

	Reset(n);

	dp[1] = (1ll * k * MOD_INV) % MOD;
	d[1] = 1;

	for (int i = 2; i <= n; ++i) {
		int p, x, y;
		scanf("%d%d%d", &p, &x, &y);

		x = (1ll * MOD_INV * x) % MOD;
		y = (1ll * MOD_INV * y) % MOD;

		d[i] = 1 + d[p];
		dp[i] = (1ll * x * dp[p] + 1ll * y * (MOD + 1 - dp[p])) % MOD;

		ancestor[0][i] = p;
		FillProbabilityMatrix(prob[0][i], x, y);
	}

	const int logn = 2 + __lg(n);
	for (int k = 1; k < logn; ++k) {
		for (int i = 1; i <= n; ++i) {
			const int j = ancestor[k - 1][i];

			MatrixMultiply(prob[k - 1][j], prob[k - 1][i], prob[k][i]);
			ancestor[k][i] = ancestor[k - 1][j];
		}
	}

	vector<int> qans;
	while (q--) {
		int i, j;
		scanf("%d%d", &i, &j);
		qans.push_back(Query(i, j));
	}
	return qans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: ", k);
		for (int x : Solve()) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}