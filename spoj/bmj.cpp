#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>

set<pii> visited = {{0, 0}};
vector<pii> coordinates{{0, 0}};
vector<pii> hexagonal_directions = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}};

int CalculateDistance(int x, int y) {
	if ((x > 0) == (y > 0)) {
		return abs(x + y);
	} else {
		return max(abs(x), abs(y));
	}
}

pii Solve() {
	int n;

	if (scanf("%d", &n) == EOF) {
		exit(0);
	}

	while (n > coordinates.size()) {
		auto [x, y] = coordinates.back();

		int min_distance = INT_MAX;
		pii next = {INT_MAX, INT_MAX};
		for (auto [dx, dy] : hexagonal_directions) {
			int nx = x + dx, ny = y + dy;
			int dis = CalculateDistance(nx, ny);
			if (visited.find({nx, ny}) == visited.end() && dis < min_distance) {
				min_distance = dis;
				next = {nx, ny};
			}
		}

		visited.insert(next);
		coordinates.push_back(next);
	}

	return coordinates[n - 1];
}

int main() {
	while (true) {
		auto [x, y] = Solve();
		printf("%d %d\n", x, y);
	}
	return 0;
}