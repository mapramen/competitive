#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<pii>> adj(N);
int subtree_size[N], centroid_ans[N];
bool is_crowded[N], is_centroid[N];

void Reset(int n) {
	for (int i = 0; i <= n; ++i) {
		adj[i].clear();
		subtree_size[i] = 0;
		centroid_ans[i] = 0;
		is_crowded[i] = false;
		is_centroid[i] = false;
	}
}

int SubtreeSizeDFS(int i, int p) {
	int ans = 1;

	for (auto [j, _] : adj[i]) {
		if (is_centroid[j] || j == p) {
			continue;
		}
		ans += SubtreeSizeDFS(j, i);
	}

	subtree_size[i] = ans;
	return ans;
}

int FindCentroidDFS(int i, int p, int s) {
	for (auto [j, _] : adj[i]) {
		if (!is_centroid[j] && j != p && 2 * subtree_size[j] > s) {
			return FindCentroidDFS(j, i, s);
		}
	}
	return i;
}

void CentroidDFS(int k, vector<int>& dp, int i, int p, int root_path_crowded_count, int root_path_sum) {
	root_path_crowded_count += is_crowded[i];

	if (root_path_crowded_count > k) {
		return;
	}

	while (dp.size() <= root_path_crowded_count) {
		dp.push_back(INT_MIN);
	}

	dp[root_path_crowded_count] = max(dp[root_path_crowded_count], root_path_sum);

	for (auto [j, w] : adj[i]) {
		if (is_centroid[j] || j == p) {
			continue;
		}
		CentroidDFS(k, dp, j, i, root_path_crowded_count, root_path_sum + w);
	}
}

int Combine(int k, bool is_crowded, vector<int>& dpi, vector<int>& dpj) {
	if (dpi.size() < dpj.size()) {
		dpi.swap(dpj);
	}

	k -= is_crowded;

	int ans = 0;
	for (int x = 0; x < dpj.size() && x <= k; ++x) {
		ans = max(ans, dpi[min((int)dpi.size() - 1, k - x)] + dpj[x]);
	}

	for (int x = 0; x < dpj.size(); ++x) {
		dpi[x] = max(dpi[x], dpj[x]);
	}

	for (int x = 1; x < dpi.size(); ++x) {
		dpi[x] = max(dpi[x], dpi[x - 1]);
	}

	return ans;
}

void ProcessCentroid(int k, int i) {
	vector<int> dpi = {0};

	int ans = 0;
	for (auto [j, w] : adj[i]) {
		if (is_centroid[j]) {
			continue;
		}

		vector<int> dpj{0};
		CentroidDFS(k, dpj, j, i, 0, w);
		ans = max(ans, Combine(k, is_crowded[i], dpi, dpj));
	}

	centroid_ans[i] = ans;
}

int CentroidDecompositionDFS(int k, int i) {
	SubtreeSizeDFS(i, 0);

	i = FindCentroidDFS(i, 0, subtree_size[i]);
	is_centroid[i] = true;

	for (auto [j, w] : adj[i]) {
		if (is_centroid[j]) {
			continue;
		}
		CentroidDecompositionDFS(k, j);
	}

	ProcessCentroid(k, i);
	is_centroid[i] = false;

	return i;
}

int Solve() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);

	Reset(n);

	while (m--) {
		int i;
		scanf("%d", &i);
		is_crowded[i] = true;
	}

	for (int e = 1; e < n; ++e) {
		int i, j, w;
		scanf("%d%d%d", &i, &j, &w);
		adj[i].push_back({j, w});
		adj[j].push_back({i, w});
	}

	CentroidDecompositionDFS(k, 1);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, centroid_ans[i]);
	}
	return ans;
}

int main() {
	int t = 1;
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}