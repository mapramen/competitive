#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001
#define LOGN 19

char op[10];
vector<vector<int>> adj(N);
int T[N];

//----------------------------------------- LCA -----------------------------------------//
int start_time[N], finish_time[N], start_time_vertex[N], euler_tour_indexes[N];
int lg[2 * N], lca_sparse_table[1 + LOGN][2 * N];
int euler_tour_index = 0, timer = 0;

void BuildLCASparseTable(int n) {
	n = 2 * n;

	for (int i = 2; i < n; ++i) {
		lg[i] = 1 + lg[(i / 2)];
	}

	for (int k = 1; k <= LOGN; ++k) {
		for (int i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i < m; ++i, ++j) {
			lca_sparse_table[k][i] = min(lca_sparse_table[k - 1][i], lca_sparse_table[k - 1][j]);
		}
	}
}

int LCA(int i, int j) {
	i = euler_tour_indexes[i], j = euler_tour_indexes[j];

	if (i > j) {
		swap(i, j);
	}

	int k = lg[j - i + 1];
	int ans = start_time_vertex[min(lca_sparse_table[k][i], lca_sparse_table[k][j - (1 << k) + 1])];
	return ans;
}
//--------------------------------------- LCA Ends ---------------------------------------//

void Reset(int n) {
	timer = 0, euler_tour_index = 0;

	for (int i = 0; i <= n; ++i) {
		adj[i].clear();
		T[i] = 0;
	}
}

void DFS(int i, int parent) {
	start_time[i] = ++timer;
	start_time_vertex[start_time[i]] = i;
	euler_tour_indexes[i] = ++euler_tour_index;
	lca_sparse_table[0][euler_tour_indexes[i]] = start_time[i];

	for (int j : adj[i]) {
		if (j == parent) {
			continue;
		}
		DFS(j, i);
		lca_sparse_table[0][++euler_tour_index] = start_time[i];
	}

	finish_time[i] = timer;
}

void PreProcess(int n) {
	DFS(1, 0);
	BuildLCASparseTable(n);
}

void UpdateBIT(int i, int x) {
	for (; i < N; i += (i & -i)) {
		T[i] += x;
	}
}

int QueryBIT(int i) {
	int ans = 0;
	for (; i > 0; i -= (i & -i)) {
		ans += T[i];
	}
	return ans;
}

void Update(int i, int j) {
	int k = LCA(i, j);

	UpdateBIT(start_time[i], 1);
	UpdateBIT(start_time[j], 1);
	UpdateBIT(start_time[k], -2);
}

int Query(int i, int j) {
	if (start_time[i] > start_time[j]) {
		swap(i, j);
	}
	return QueryBIT(finish_time[j]) - QueryBIT(start_time[j] - 1);
}

void Solve() {
	int n, q;
	scanf("%d%d", &n, &q);

	Reset(n);

	for (int e = 1; e < n; ++e) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	PreProcess(n);

	while (q--) {
		int i, j;
		scanf("%s%d%d", op, &i, &j);

		if (op[0] == 'P') {
			Update(i, j);
			continue;
		}

		printf("%d\n", Query(i, j));
	}
}

int main() {
	int t = 1;
	while (t--) {
		Solve();
	}
	return 0;
}