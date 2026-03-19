#include <bits/stdc++.h>

using namespace std;

void CheckAndUpdate(
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>& Q,
		vector<long long>& dist,
		const int i,
		const long long new_dist) {
	if (new_dist >= dist[i]) {
		return;
	}

	dist[i] = new_dist;
	Q.push({new_dist, i});
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> c(m + 1);
	for (int j = 1; j <= m; ++j) {
		scanf("%d", &c[j]);
	}

	vector<vector<pair<int, int>>> adj(n + m + 1);
	for (int j = 1; j <= m; ++j) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int i;
			scanf("%d", &i);

			adj[i].push_back({c[j], n + j});
			adj[n + j].push_back({0, i});
		}
	}

	vector<long long> dist(n + m + 1, LLONG_MAX);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> Q;

	CheckAndUpdate(Q, dist, 1, 0);

	while (!Q.empty()) {
		const auto [d, i] = Q.top();
		Q.pop();

		if (d > dist[i]) {
			continue;
		}

		for (const auto& [w, j] : adj[i]) {
			CheckAndUpdate(Q, dist, j, d + w);
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%lld ", dist[i]);
	}
	printf("\n");

	return 0;
}