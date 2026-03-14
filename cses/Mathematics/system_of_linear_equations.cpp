#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int ModularExponentation(int a, int n) {
	int ans = 1;
	for (; n > 0; n /= 2) {
		if (n % 2 == 1) {
			ans = (1ll * ans * a) % MOD;
		}
		a = (1ll * a * a) % MOD;
	}
	return ans % MOD;
}

int ModularInverse(int a) {
	return ModularExponentation(a, MOD - 2);
}

vector<int> GaussElimination(vector<vector<int>> A) {
	const int n = A.size(), m = A.front().size() - 1;

	vector<int> where(m, -1);

	for (int row = 0, col = 0; row < n && col < m; ++col) {
		int p = row;
		while (p < n && A[p][col] == 0) {
			++p;
		}

		if (p == n) {
			continue;
		}

		if (p != row) {
			swap(A[row], A[p]);
		}
		where[col] = row;

		for (int j = col, p = ModularInverse(A[row][col]); j <= m; ++j) {
			A[row][j] = (1ll * p * A[row][j]) % MOD;
		}

		for (int k = 0; k < n; ++k) {
			if (k == row) {
				continue;
			}

			for (int j = col, p = A[k][col]; j <= m; ++j) {
				A[k][j] = (A[k][j] + MOD - (1ll * p * A[row][j]) % MOD) % MOD;
			}
		}

		++row;
	}

	vector<int> ans(m);
	for (int i = 0; i < m; ++i) {
		if (where[i] != -1) {
			ans[i] = A[where[i]][m];
		}
	}

	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			sum = (sum + 1ll * A[i][j] * ans[j]) % MOD;
		}

		if (sum != A[i][m]) {
			return {-1};
		}
	}

	return ans;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<vector<int>> A(n, vector<int>(m + 1));
	for (auto& a : A) {
		for (int& x : a) {
			scanf("%d", &x);
		}
	}

	for (const int x : GaussElimination(A)) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}