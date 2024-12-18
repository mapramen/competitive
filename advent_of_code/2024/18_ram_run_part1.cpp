#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pii> ReadInputs() {
	vector<pii> inputs;
	for (int x, y; scanf("%d,%d", &x, &y) != EOF;) {
		inputs.push_back({x, y});
	}
	return inputs;
}

void CheckAndPush(const vector<string>& s,
									vector<vector<int>>& dist,
									queue<pii>& Q,
									int x,
									int y,
									int dxy) {
	const int n = s.size(), m = s.front().size();
	if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#' || dist[x][y] <= dxy) {
		return;
	}

	dist[x][y] = dxy;
	Q.push({x, y});
}

int BFS(const vector<string>& s) {
	const int n = s.size(), m = s.front().size();

	queue<pii> Q;
	vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

	CheckAndPush(s, dist, Q, 0, 0, 0);

	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();

		CheckAndPush(s, dist, Q, x - 1, y, dist[x][y] + 1);
		CheckAndPush(s, dist, Q, x + 1, y, dist[x][y] + 1);
		CheckAndPush(s, dist, Q, x, y - 1, dist[x][y] + 1);
		CheckAndPush(s, dist, Q, x, y + 1, dist[x][y] + 1);
	}

	return dist[n - 1][m - 1];
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vector<pii> byte_coordinates = ReadInputs();

	vector<string> s(n, string(m, '.'));
	for (int i = 0; i < k; ++i) {
		auto [x, y] = byte_coordinates[i];
		s[x][y] = '#';
	}

	printf("%d\n", BFS(s));

	return 0;
}