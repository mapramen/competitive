#include <bits/stdc++.h>

using namespace std;

vector<int> ReadArray(int n) {
	vector<int> a(n);
	for (auto& x : a) {
		scanf("%d", &x);
	}
	return a;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	const auto& A = ReadArray(n);
	const auto& B = ReadArray(m);

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	vector<int> lcs;
	for (int i = n, j = m; i > 0 && j > 0;) {
		if (A[i - 1] == B[j - 1]) {
			lcs.push_back(A[i - 1]);
			i--;
			j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}

	reverse(lcs.begin(), lcs.end());
	printf("%lu\n", lcs.size());
	for (const auto& x : lcs) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}