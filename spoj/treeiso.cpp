#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

map<vector<int>, int> M;

vector<vector<int>> ReadTree(int n) {
	vector<vector<int>> adj(n + 1);

	for (int x = 1; x < n; ++x) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	return adj;
}

vector<int> DistantPath(vector<vector<int>> &adj, int i) {
	int n = adj.size();
	vector<int> parent(n);
	queue<int> Q;

	parent[i] = -1;
	Q.push(i);

	while (!Q.empty()) {
		i = Q.front();
		Q.pop();
		for (int j : adj[i]) {
			if (parent[j] != 0) {
				continue;
			}
			parent[j] = i;
			Q.push(j);
		}
	}

	vector<int> v;
	for (; i != -1; i = parent[i]) {
		v.push_back(i);
	}
	reverse(v.begin(), v.end());

	return v;
}

vector<int> Centers(vector<vector<int>> &adj) {
	vector<int> diameter = DistantPath(adj, DistantPath(adj, 1).back());
	int n = diameter.size();

	return n % 2 == 1
						 ? vector<int>{diameter[n / 2]}
						 : vector<int>{diameter[(n / 2) - 1], diameter[(n / 2)]};
}

int VectorToInt(vector<int> &v) {
	sort(v.begin(), v.end());

	auto it = M.find(v);
	if (it != M.end()) {
		return it->second;
	}

	int x = M.size();
	M[v] = x;
	return x;
}

int DFS(vector<vector<int>> &adj, int i, int p) {
	vector<int> v;
	for (int j : adj[i]) {
		if (j == p) {
			continue;
		}
		v.push_back(DFS(adj, j, i));
	}
	return VectorToInt(v);
}

bool Solve() {
	int n;
	scanf("%d", &n);

	vector<vector<int>> adj1 = ReadTree(n);
	vector<vector<int>> adj2 = ReadTree(n);

	vector<int> centers1 = Centers(adj1);
	vector<int> centers2 = Centers(adj2);

	if (centers1.size() != centers2.size()) {
		return false;
	}

	return DFS(adj1, centers1.front(), 0) == DFS(adj2, centers2.front(), 0) || DFS(adj1, centers1.front(), 0) == DFS(adj2, centers2.back(), 0);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%s\n", Solve() ? "YES" : "NO");
	}
	return 0;
}