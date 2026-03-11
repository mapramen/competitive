#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> moves{{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void CheckAndPush(queue<pair<int, int>>& Q, vector<vector<int>>& d, int x, int y, int new_d) {
	if (x < 0 || x >= d.size() || y < 0 || y >= d.size() || d[x][y] != INT_MAX) {
		return;
	}

	d[x][y] = new_d;
	Q.push({x, y});
}

int main() {
	int n;
	scanf("%d", &n);

	vector<vector<int>> d(n, vector<int>(n, INT_MAX));
	queue<pair<int, int>> Q;

	CheckAndPush(Q, d, 0, 0, 0);

	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();

		for (auto [dx, dy] : moves) {
			CheckAndPush(Q, d, x + dx, y + dy, d[x][y] + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	return 0;
}