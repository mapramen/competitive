#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsPointInsideSegment(int x1, int y1, int x2, int y2, int x, int y) {
	int dx1 = x - x1, dy1 = y - y1;
	int dx2 = x - x2, dy2 = y - y2;
	return (dx1 * dy2 == dx2 * dy1) && (dx1 * dx2 <= 0) && (dy1 * dy2 <= 0);
}

int CalculatePointsInsideSegment(const vector<pii>& points, int x1, int y1, int x2, int y2) {
	int ans = 0;
	for (const auto& point : points) {
		ans += IsPointInsideSegment(x1, y1, x2, y2, point.first, point.second);
	}
	return ans;
}

vector<int> Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<pii> points(n);
	for (auto& point : points) {
		scanf("%d%d", &point.first, &point.second);
	}

	vector<int> ans;
	while (m--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ans.push_back(CalculatePointsInsideSegment(points, x1, y1, x2, y2));
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int x : Solve()) {
			printf("%d\n", x);
		}
	}
	return 0;
}