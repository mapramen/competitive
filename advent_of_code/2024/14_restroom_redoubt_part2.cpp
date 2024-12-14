#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pii CalculateFinalPosition(const int t, const int n, const int m, const int px, const int py, const int vx, const int vy) {
	int fx = (px + 1ll * vx * t) % n;
	int fy = (py + 1ll * vy * t) % m;

	if (fx < 0) {
		fx += n;
	}

	if (fy < 0) {
		fy += m;
	}

	return {fx, fy};
}

void PrintRoom(const int n, const int m, const vector<tuple<int, int, int, int>>& points, int t) {
	vector<string> room(m, string(n, '.'));

	for (const auto& [px, py, vx, vy] : points) {
		auto [fx, fy] = CalculateFinalPosition(t, n, m, px, py, vx, vy);
		room[fy][fx] = '#';
	}

	printf("t = %d\n", t);
	for (int i = 0; i < m; ++i) {
		printf("%s\n", room[i].c_str());
	}
	printf("\n");
}

int main() {
	int n, m;
	scanf("n=%d, m=%d\n", &n, &m);

	vector<tuple<int, int, int, int>> points;

	for (int px, py, vx, vy; scanf("p=%d,%d v=%d,%d\n", &px, &py, &vx, &vy) != EOF;) {
		points.push_back({px, py, vx, vy});
	}

	for (int t = 22; t < n * m; t += n) {
		PrintRoom(n, m, points, t);
	}

	return 0;
}