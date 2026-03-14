#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n + 2);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	a[0] = a[n + 1] = INT_MAX;
	vector<vector<int>> adj(n + 2);
	vector<int> indegree(n + 2);

	vector<int> left_indices{0};
	for (int i = 1; i <= n; ++i) {
		while (!left_indices.empty() && a[left_indices.back()] <= a[i]) {
			left_indices.pop_back();
		}

		adj[left_indices.back()].push_back(i);
		++indegree[i];

		left_indices.push_back(i);
	}

	vector<int> right_indices{n + 1};
	for (int i = n; i > 0; --i) {
		while (!right_indices.empty() && a[right_indices.back()] <= a[i]) {
			right_indices.pop_back();
		}

		adj[right_indices.back()].push_back(i);
		++indegree[i];

		right_indices.push_back(i);
	}

	vector<int> dp(n + 2);
	queue<int> Q;
	Q.push(0);
	Q.push(n + 1);

	while (!Q.empty()) {
		const int i = Q.front();
		Q.pop();

		for (const int j : adj[i]) {
			dp[j] = max(dp[j], 1 + dp[i]);
			if (--indegree[j] == 0) {
				Q.push(j);
			}
		}
	}

	const int ans = *max_element(dp.begin(), dp.end());
	printf("%d\n", ans);

	return 0;
}