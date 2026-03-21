#include <bits/stdc++.h>

using namespace std;

#define N 1001

long long d[N][N];
tuple<int, int, string> parent[N][N];
queue<pair<int, int>> Q;

void CheckAndPush(
		const int i,
		const int j,
		const long long parent_dist,
		const string& op,
		const int di,
		const int dj) {
	const int ni = i + di, nj = j + dj;
	const auto new_dist = parent_dist + max(abs(di), abs(dj));
	if (d[ni][nj] != LLONG_MAX) {
		return;
	}

	d[ni][nj] = new_dist;
	parent[ni][nj] = {i, j, op};
	Q.push({ni, nj});
}

int main() {
	int a, b, x;
	scanf("%d%d%d", &a, &b, &x);

	if (x > a) {
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= b; ++j) {
			d[i][j] = LLONG_MAX;
		}
	}

	d[0][0] = 0;
	Q.push({0, 0});

	while (!Q.empty()) {
		const auto [i, j] = Q.front();
		Q.pop();

		const auto dist = d[i][j];

		CheckAndPush(i, j, dist, "FILL A", a - i, 0);
		CheckAndPush(i, j, dist, "FILL B", 0, b - j);
		CheckAndPush(i, j, dist, "EMPTY A", -i, 0);
		CheckAndPush(i, j, dist, "EMPTY B", 0, -j);
		CheckAndPush(i, j, dist, "MOVE A B", -min(i, b - j), min(i, b - j));
		CheckAndPush(i, j, dist, "MOVE B A", min(j, a - i), -min(j, a - i));
	}

	tuple<long long, int, int> best = {LLONG_MAX, -1, -1};
	for (int j = 0; j <= b; ++j) {
		best = min(best, {d[x][j], x, j});
	}

	if (get<0>(best) == LLONG_MAX) {
		printf("-1\n");
		return 0;
	}

	vector<string> ans;
	for (auto [dist, i, j] = best; d[i][j] != 0; tie(i, j, ignore) = parent[i][j]) {
		ans.push_back(get<2>(parent[i][j]));
	}
	reverse(ans.begin(), ans.end());

	printf("%lu %lld\n", ans.size(), get<0>(best));
	for (const auto& op : ans) {
		printf("%s\n", op.c_str());
	}

	return 0;
}