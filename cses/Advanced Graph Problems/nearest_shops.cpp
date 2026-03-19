#include <bits/stdc++.h>

using namespace std;

void CheckAndPush(
		queue<tuple<int, int, int>>& Q,
		vector<vector<pair<int, int>>>& D,
		const int dis,
		const int i,
		const int source) {
	auto& d = D[i];
	if (d.size() == 2) {
		return;
	}

	for (const auto& [_, s] : d) {
		if (s == source) {
			return;
		}
	}

	d.push_back({dis, source});
	Q.push({dis, i, source});
}

int Query(const vector<pair<int, int>>& d, const int i) {
	if (d.empty()) {
		return -1;
	}

	if (d.front().second != i) {
		return d.front().first;
	}

	return d.size() == 1 ? -1 : d.back().first;
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vector<vector<pair<int, int>>> D(n + 1);
	queue<tuple<int, int, int>> Q;

	while (k--) {
		int i;
		scanf("%d", &i);
		CheckAndPush(Q, D, 0, i, i);
	}

	vector<vector<int>> adj(n + 1);
	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	while (!Q.empty()) {
		const auto [dis, i, source] = Q.front();
		Q.pop();

		for (const int j : adj[i]) {
			CheckAndPush(Q, D, dis + 1, j, source);
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d ", Query(D[i], i));
	}
	printf("\n");

	return 0;
}