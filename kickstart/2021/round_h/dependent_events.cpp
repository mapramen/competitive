#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define K 2
#define N 200001
#define LOGN 19
#define MOD 1000000007
#define MOD_INV 142857001

int d[N], dp[N];
vector<vector<pair<int, vector<vector<int>>>>> T(LOGN, vector<pair<int, vector<vector<int>>>>(N));

vector<vector<int>> GetIdentityMatrix() {
	vector<vector<int>> A(K, vector<int>(K));
	for (int i = 0; i < K; ++i) {
		A[i][i] = 1;
	}
	return A;
}

vector<vector<int>> GetProbabilityMatrix(const int a, const int b) {
	vector<vector<int>> A(K, vector<int>(K));
	A[0][0] = a;
	A[0][1] = (MOD + 1 - a) % MOD;
	A[1][0] = b;
	A[1][1] = (MOD + 1 - b) % MOD;
	return A;
}

void Reset(const int n) {
	const int logn = 2 + __lg(n);
	for (int k = 0; k < logn; ++k) {
		T[k][0] = {0, GetIdentityMatrix()};
	}
	T[0][1] = {0, GetIdentityMatrix()};
}

vector<vector<int>> MatrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	vector<vector<int>> C(K, vector<int>(K));
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			int ans = 0;
			for (int k = 0; k < K; ++k) {
				ans = (ans + 1ll * A[i][k] * B[k][j]) % MOD;
			}
			C[i][j] = ans;
		}
	}
	return C;
}

int Query(int i, int j) {
	if (d[j] < d[i]) {
		swap(i, j);
	}

	const int logn = 2 + __lg(d[j]);

	vector<vector<int>> B = GetIdentityMatrix();
	for (int k = logn - 1, x = d[j] - d[i]; k > -1 && x > 0; --k) {
		if ((1 << k) > x) {
			continue;
		}

		B = MatrixMultiply(T[k][j].second, B);
		j = T[k][j].first;
		x ^= (1 << k);
	}

	if (j == i) {
		return (1ll * dp[i] * B[0][0]) % MOD;
	}

	vector<vector<int>> A = GetIdentityMatrix();
	for (int k = logn - 1; k > -1; --k) {
		if (T[k][i].first == T[k][j].first) {
			continue;
		}

		A = MatrixMultiply(T[k][i].second, A);
		B = MatrixMultiply(T[k][j].second, B);

		i = T[k][i].first;
		j = T[k][j].first;
	}

	A = MatrixMultiply(T[0][i].second, A);
	B = MatrixMultiply(T[0][j].second, B);

	const int lca = T[0][i].first;
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
		T[0][i] = {p, GetProbabilityMatrix(x, y)};
	}

	const int logn = 2 + __lg(n);
	for (int k = 1; k < logn; ++k) {
		for (int i = 1; i <= n; ++i) {
			const auto [j, _] = T[k - 1][i];
			T[k][i] = {T[k - 1][j].first, MatrixMultiply(T[k - 1][j].second, T[k - 1][i].second)};
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