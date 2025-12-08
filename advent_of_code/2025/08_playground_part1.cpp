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

void Union(vector<int>& parent, vector<int>& sz, int i, int j) {
	i = Find(parent, i), j = Find(parent, j);
	if (i == j) {
		return;
	}

	if (i > j) {
		swap(i, j);
	}

	parent[j] = i;
	sz[i] += sz[j];
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Please provide an integer argument\n";
		return 1;
	}

	int k = stoi(argv[1]);
	const auto& a = ReadInputs();
	const int n = a.size();

	vector<tuple<long long, int, int>> edges;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			edges.push_back({CalculateDistance(a[i], a[j]), i, j});
		}
	}
	sort(edges.begin(), edges.end());

	vector<int> parent(n), sz(n);
	iota(parent.begin(), parent.end(), 0);
	fill(sz.begin(), sz.end(), 1);

	for (const auto [_, i, j] : edges) {
		Union(parent, sz, i, j);
		if (--k == 0) {
			break;
		}
	}

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		if (parent[i] != i) {
			continue;
		}
		v.push_back(sz[i]);
	}

	if (v.size() > 3) {
		const int m = v.size();
		nth_element(v.begin(), v.begin() + 3, v.end(), greater<int>());
		v.resize(3);
	}

	const long long ans = accumulate(v.begin(), v.end(), 1ll, multiplies<int>());
	cout << ans << '\n';

	return 0;
}