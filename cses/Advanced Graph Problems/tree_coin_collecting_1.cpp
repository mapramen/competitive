#include <bits/stdc++.h>

using namespace std;

#define N 200001
#define LOGN 18

int a[N], depth[N];
vector<vector<int>> adj(N);
vector<vector<pair<int, int>>> lca_table(LOGN, vector<pair<int, int>>(N));

void BFS(const int n) {
	queue<int> Q;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			a[i] = n;
			continue;
		}

		Q.push(i);
		a[i] = 0;
	}

	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();

		for (auto j : adj[i]) {
			if (a[j] != n) {
				continue;
			}
			a[j] = a[i] + 1;
			Q.push(j);
		}
	}
}

void DFS(int i, int p) {
	for (auto j : adj[i]) {
		if (j == p) {
			continue;
		}

		depth[j] = depth[i] + 1;
		lca_table[0][j] = {i, min(a[i], a[j])};
		DFS(j, i);
	}
}

int Query(int i, int j) {
	int ans = depth[i] + depth[j];
	int min_dist = min(a[i], a[j]);

	if (depth[i] < depth[j]) {
		swap(i, j);
	}

	for (int k = LOGN - 1; k >= 0; --k) {
		if (depth[i] - (1 << k) >= depth[j]) {
			min_dist = min(min_dist, lca_table[k][i].second);
			i = lca_table[k][i].first;
		}
	}

	if (i == j) {
		return ans - 2 * depth[i] + 2 * min_dist;
	}

	for (int k = LOGN - 1; k >= 0; --k) {
		if (lca_table[k][i].first != lca_table[k][j].first) {
			min_dist = min({min_dist, lca_table[k][i].second, lca_table[k][j].second});
			i = lca_table[k][i].first;
			j = lca_table[k][j].first;
		}
	}

	min_dist = min(min_dist, min(lca_table[0][i].second, lca_table[0][j].second));
	return ans - 2 * depth[lca_table[0][i].first] + 2 * min_dist;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int e = 1; e < n; ++e) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	BFS(n);
	DFS(1, 0);

	for (int k = 1; k < LOGN; ++k) {
		for (int i = 1; i <= n; ++i) {
			lca_table[k][i].first = lca_table[k - 1][lca_table[k - 1][i].first].first;
			lca_table[k][i].second = min(lca_table[k - 1][i].second, lca_table[k - 1][lca_table[k - 1][i].first].second);
		}
	}

	while (q--) {
		int i, j;
		scanf("%d%d", &i, &j);
		printf("%d\n", Query(i, j));
	}

	return 0;
}