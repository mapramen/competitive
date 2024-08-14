#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

vector<vector<int>> adj(N);
int color[N];

int parent[N], depth[N], heavy[N], head[N], tail[N], chain_position[N], chain_position_to_vertex[2 * N];
int chain_length;

int T[2][2 * N];
set<pii> color_intervals[2];

void Reset(int n) {
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
	}
}

int HeavyChildDFS(int i, int p) {
	int size = 1, max_child_size = 0;

	parent[i] = p;
	depth[i] = 1 + depth[p];

	for (int j : adj[i]) {
		if (j == p) {
			continue;
		}

		int size_j = HeavyChildDFS(j, i);
		size += size_j;

		if (size_j > max_child_size) {
			max_child_size = size_j;
			heavy[i] = j;
		}
	}

	return size;
}

void HeavyChildDecomposeDFS(int h, int i) {
	head[i] = h;
	tail[h] = i;
	chain_position[i] = ++chain_length;
	chain_position_to_vertex[chain_length] = i;

	if (heavy[i] != 0) {
		HeavyChildDecomposeDFS(h, heavy[i]);
	}

	for (int j : adj[i]) {
		if (j == parent[i] || j == heavy[i]) {
			continue;
		}
		++chain_length;
		HeavyChildDecomposeDFS(j, j);
	}
}

void UpdateBIT(int T[], int i, int val) {
	for (; i <= chain_length; i += i & -i) {
		T[i] += val;
	}
}

void UpdateBIT(int T[], int i, int j, int val) {
	UpdateBIT(T, i, val);
	UpdateBIT(T, j + 1, -val);
}

int QueryBIT(int T[], int i) {
	int ans = 0;
	for (; i > 0; i -= i & -i) {
		ans += T[i];
	}
	return ans;
}

void PreProcess(int n) {
	chain_length = 0;
	for (int i = 1; i <= n; ++i) {
		color[i] = 0;
		heavy[i] = 0;
	}

	color_intervals[0].clear();
	color_intervals[1].clear();

	for (int i = 0; i <= 2 * n; ++i) {
		T[0][i] = 0;
		T[1][i] = 0;
	}

	HeavyChildDFS(1, 0);
	HeavyChildDecomposeDFS(1, 1);

	for (int i = 1; i <= n; ++i) {
		if (head[i] == i) {
			color_intervals[0].insert({chain_position[i], chain_position[tail[i]]});
		}

		for (int j = i; j != 0; j = parent[head[j]]) {
			UpdateBIT(T[0], chain_position[head[j]], chain_position[j], 1);
		}

		UpdateBIT(T[1], chain_position[i], chain_position[i], 1);
	}
}

int TopVertexWithSameColor(int i) {
	auto [same_color_chain_start, _] = *prev(color_intervals[color[i]].upper_bound({chain_position[i], INT_MAX}));

	if (chain_position[head[i]] != same_color_chain_start) {
		return chain_position_to_vertex[same_color_chain_start];
	}

	if (parent[head[i]] == 0 || color[parent[head[i]]] != color[i]) {
		return head[i];
	}

	return TopVertexWithSameColor(parent[head[i]]);
}

void Update(int i, int val) {
	int c = color[i];
	int j = TopVertexWithSameColor(i);

	if (parent[j] != 0) {
		j = parent[j];
	}

	i = parent[i];
	if (i == 0) {
		return;
	}

	for (; head[i] != head[j]; i = parent[head[i]]) {
		UpdateBIT(T[c], chain_position[head[i]], chain_position[i], val);
	}

	UpdateBIT(T[c], chain_position[j], chain_position[i], val);
}

void RemoveFromColorInterval(set<pii> &S, int i) {
	auto [interval_start, interval_end] = *prev(S.upper_bound({i, INT_MAX}));
	S.erase({interval_start, interval_end});

	if (interval_start < i) {
		S.insert({interval_start, i - 1});
	}

	if (i < interval_end) {
		S.insert({i + 1, interval_end});
	}
}

void AddToColorInterval(set<pii> &S, int i) {
	int interval_start = i, interval_end = i;

	while (!S.empty() && interval_end < S.rbegin()->first) {
		auto [next_interval_start, next_interval_end] = *S.upper_bound({i, INT_MAX});
		if (i + 1 != next_interval_start) {
			break;
		}

		interval_end = next_interval_end;
		S.erase({next_interval_start, next_interval_end});
	}

	while (!S.empty() && S.begin()->second < interval_start) {
		auto [prev_interval_start, prev_interval_end] = *prev(S.lower_bound({interval_start, INT_MAX}));
		if (prev_interval_end + 1 != interval_start) {
			break;
		}

		interval_start = prev_interval_start;
		S.erase({prev_interval_start, prev_interval_end});
	}

	S.insert({interval_start, interval_end});
}

void ToggleColor(int i) {
	Update(i, -QueryBIT(T[color[i]], chain_position[i]));
	RemoveFromColorInterval(color_intervals[color[i]], chain_position[i]);

	color[i] ^= 1;

	AddToColorInterval(color_intervals[color[i]], chain_position[i]);
	Update(i, QueryBIT(T[color[i]], chain_position[i]));
}

int Query(int i) {
	int k = TopVertexWithSameColor(i);
	return QueryBIT(T[color[k]], chain_position[k]);
}

void Solve() {
	int n;
	scanf("%d", &n);

	Reset(n);

	for (int e = 1; e < n; ++e) {
		int i, j;
		scanf("%d%d", &i, &j);

		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	PreProcess(n);

	int q;
	scanf("%d", &q);

	while (q--) {
		int t, i;
		scanf("%d%d", &t, &i);

		if (t == 1) {
			ToggleColor(i);
		} else {
			printf("%d\n", Query(i));
		}
	}
}

int main() {
	int t = 1;
	while (t--) {
		Solve();
	}
	return 0;
}