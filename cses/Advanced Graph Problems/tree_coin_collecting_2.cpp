#include <bits/stdc++.h>

using namespace std;

#define N 200001
#define LOGN 18

int c[N], degree[N], nearest_boundary_vertex[N], depth[N];
vector<vector<int>> adj(N);
vector<vector<int>> lca_table(LOGN, vector<int>(N));

int BFS(const int n) {
	vector<bool> visited(n + 1);

	queue<int> Q;
	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 1 && c[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();

		visited[i] = true;

		for (const auto j : adj[i]) {
			--degree[j];
			if (degree[j] == 1 && c[j] == 0) {
				Q.push(j);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		visited[i] = !visited[i];
		if (!visited[i]) {
			continue;
		}

		nearest_boundary_vertex[i] = i;
		Q.push(i);
	}

	const int m = Q.size();

	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();

		for (const auto j : adj[i]) {
			if (nearest_boundary_vertex[j] != 0) {
				continue;
			}
			nearest_boundary_vertex[j] = nearest_boundary_vertex[i];
			Q.push(j);
		}
	}

	return m;
}

void DFS(int i, int p) {
	for (auto j : adj[i]) {
		if (j == p) {
			continue;
		}

		depth[j] = depth[i] + 1;
		lca_table[0][j] = i;
		DFS(j, i);
	}
}

int QueryDistance(int i, int j) {
	int ans = depth[i] + depth[j];

	if (depth[i] < depth[j]) {
		swap(i, j);
	}

	for (int k = LOGN - 1; k >= 0; --k) {
		if (depth[i] - (1 << k) >= depth[j]) {
			i = lca_table[k][i];
		}
	}

	if (i == j) {
		return ans - 2 * depth[i];
	}

	for (int k = LOGN - 1; k >= 0; --k) {
		if (lca_table[k][i] != lca_table[k][j]) {
			i = lca_table[k][i];
			j = lca_table[k][j];
		}
	}

	return ans - 2 * depth[lca_table[0][i]];
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}

	for (int e = 1; e < n; ++e) {
		int i, j;
		scanf("%d%d", &i, &j);

		adj[i].push_back(j);
		adj[j].push_back(i);

		++degree[i];
		++degree[j];
	}

	DFS(1, 0);
	for (int k = 1; k < LOGN; ++k) {
		for (int i = 1; i <= n; ++i) {
			lca_table[k][i] = lca_table[k - 1][lca_table[k - 1][i]];
		}
	}

	const int m = BFS(n);

	while (q--) {
		int i, j;
		scanf("%d%d", &i, &j);

		const int boundary_i = nearest_boundary_vertex[i];
		const int boundary_j = nearest_boundary_vertex[j];

		const int ans = 2 * (m - 1) + QueryDistance(i, boundary_i) + QueryDistance(j, boundary_j) - QueryDistance(boundary_i, boundary_j);
		printf("%d\n", ans);
	}

	return 0;
}