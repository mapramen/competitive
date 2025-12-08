#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> ReadInputs() {
	vector<tuple<int, int, int>> v;
	for (int x, y, z; scanf("%d,%d,%d", &x, &y, &z) != EOF; v.push_back({x, y, z}));
	return v;
}

long long CalculateDistance(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
	const auto [x1, y1, z1] = a;
	const auto [x2, y2, z2] = b;

	const int dx = x2 - x1, dy = y2 - y1, dz = z2 - z1;
	return 1ll * dx * dx + 1ll * dy * dy + 1ll * dz * dz;
}

int Find(vector<int>& parent, const int i) {
	return parent[i] == i ? i : parent[i] = Find(parent, parent[i]);
}

bool Union(vector<int>& parent, int i, int j) {
	i = Find(parent, i), j = Find(parent, j);
	if (i == j) {
		return false;
	}

	if (i > j) {
		swap(i, j);
	}

	parent[j] = i;
	return true;
}

int main() {
	const auto& a = ReadInputs();
	const int n = a.size();

	vector<tuple<long long, int, int>> edges;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			edges.push_back({CalculateDistance(a[i], a[j]), i, j});
		}
	}
	sort(edges.begin(), edges.end());

	vector<int> parent(n);
	iota(parent.begin(), parent.end(), 0);

	int k = n;
	for (const auto [_, i, j] : edges) {
		k -= Union(parent, i, j);
		if (k == 1) {
			cout << 1ll * get<0>(a[i]) * get<0>(a[j]) << '\n';
			break;
		}
	}

	return 0;
}