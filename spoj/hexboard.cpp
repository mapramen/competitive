#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define tcoordinate pair<pii, pii>
#define tedge pair<pii, pii>
#define N 20

vector<vector<string>> S(N);

vector<tcoordinate> directions = {
		{{0, 1}, {0, 2}},
		{{-1, 1}, {-2, 1}},
		{{-1, 0}, {-2, -1}},
		{{0, -1}, {0, -2}},
		{{1, -1}, {2, -1}},
		{{1, 0}, {2, 1}},
};

int CalculateDistance(int x, int y) {
	if ((x > 0) == (y > 0)) {
		return abs(x + y);
	} else {
		return max(abs(x), abs(y));
	}
}

void AddEdges(vector<tedge>& edges, int x, int y) {
	edges.push_back({{x, y}, {x + 1, y - 1}});
	edges.push_back({{x + 1, y - 1}, {x + 2, y - 1}});
	edges.push_back({{x + 2, y - 1}, {x + 3, y}});
	edges.push_back({{x + 3, y}, {x + 2, y + 1}});
	edges.push_back({{x + 2, y + 1}, {x + 1, y + 1}});
	edges.push_back({{x + 1, y + 1}, {x, y}});
}

pii NormalizeCoordinates(vector<tedge>& edges) {
	int base_x = INT_MAX, base_y = INT_MAX;
	for (auto [a, b] : edges) {
		auto [ax, ay] = a;
		auto [bx, by] = b;
		base_x = min(base_x, min(ax, bx));
		base_y = min(base_y, min(ay, by));
	}

	for (auto& [a, b] : edges) {
		auto [ax, ay] = a;
		auto [bx, by] = b;
		a = {ax - base_x, ay - base_y};
		b = {bx - base_x, by - base_y};
	}

	int max_x = INT_MIN, max_y = INT_MIN;
	for (auto [a, b] : edges) {
		auto [ax, ay] = a;
		auto [bx, by] = b;
		max_x = max(max_x, max(ax, bx));
		max_y = max(max_y, max(ay, by));
	}

	return {max_x + 1, max_y + 1};
}

vector<string> GenerateHexBoard(vector<tedge> edges) {
	auto [n, m] = NormalizeCoordinates(edges);

	vector<string> S = vector<string>(m, string(n, ' '));
	for (auto [a, b] : edges) {
		if (a > b) {
			swap(a, b);
		}

		auto [ax, ay] = a;
		auto [bx, by] = b;

		if (ay == by) {
			S[ay][ax] = '_';
			continue;
		}

		if (by == ay - 1) {
			S[ay][ax] = '/';
			continue;
		}

		if (by == ay + 1) {
			S[by][bx - 1] = '\\';
			continue;
		}

		assert(false);
	}

	for (auto& s : S) {
		while (s.back() == ' ') {
			s.pop_back();
		}
	}

	return S;
}

void Initialize() {
	vector<set<pii>> V(N);
	queue<tcoordinate> Q;

	Q.push({{0, 0}, {0, 0}});
	while (!Q.empty()) {
		auto [hex_coordinates, rec_coordinates] = Q.front();
		Q.pop();

		auto [hx, hy] = hex_coordinates;
		auto [rx, ry] = rec_coordinates;

		int dis = CalculateDistance(hx, hy);

		if (dis >= N || V[dis].find(rec_coordinates) != V[dis].end()) {
			continue;
		}

		V[dis].insert(rec_coordinates);

		for (auto [hex_direction, rec_direction] : directions) {
			auto [dhx, dhy] = hex_direction;
			auto [drx, dry] = rec_direction;
			Q.push({{hx + dhx, hy + dhy}, {rx + drx, ry + dry}});
		}
	}

	vector<tedge> edges;
	for (int n = 0; n < N; ++n) {
		for (auto [x, y] : V[n]) {
			AddEdges(edges, x, y);
		}

		sort(edges.begin(), edges.end());
		edges.erase(unique(edges.begin(), edges.end()), edges.end());

		S[n] = GenerateHexBoard(edges);
	}
}

void Solve() {
	int n;
	scanf("%d", &n);

	if (n == -1) {
		exit(0);
	}

	--n;

	for (auto& s : S[n]) {
		printf("%s\n", s.c_str());
	}
	printf("***\n");
}

int main() {
	Initialize();
	while (true) {
		Solve();
	}
	return 0;
}