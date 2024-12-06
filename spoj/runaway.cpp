#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ZOOM 10

mt19937 rnd(random_device{}());
uniform_real_distribution<double> dis_real(0, 1);
const vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
uniform_int_distribution<int> dis_dir(0, directions.size() - 1);

double Dist2(pll a, pll b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

double CalculateMinDistance(vector<pll>& points, pll p) {
	double min_dist = Dist2(p, points.front());
	for (auto& q : points) {
		min_dist = min(min_dist, Dist2(p, q));
	}
	return min_dist;
}

bool ShouldReplace(double e, double e_new, double t) {
	if (e_new > e) {
		return true;
	}
	double p = exp((e_new - e) / t);
	double x = dis_real(rnd);
	return x < p;
}

pair<double, pll> GetInitialBestGuess(vector<pll>& points, ll n, ll m, int k) {
	uniform_int_distribution<ll> dis_x(0, n);
	uniform_int_distribution<ll> dis_y(0, m);

	k = 10000;

	double max_dist = CalculateMinDistance(points, {0, 0});
	pll best_point = {0, 0};
	for (int i = 0; i < k; ++i) {
		pll p = {dis_x(rnd), dis_y(rnd)};
		double dist = CalculateMinDistance(points, p);
		if (dist > max_dist) {
			max_dist = dist;
			best_point = p;
		}
	}
	return {max_dist, best_point};
}

pdd Solve() {
	ll n, m, k;
	scanf("%lld%lld%lld", &n, &m, &k);

	vector<pll> points(k);
	for (int i = 0; i < k; i++) {
		scanf("%lld%lld", &points[i].first, &points[i].second);
	}

	n *= ZOOM, m *= ZOOM;
	for (auto& [x, y] : points) {
		x *= ZOOM, y *= ZOOM;
	}

	auto [max_dist, best_point] = GetInitialBestGuess(points, n, m, k);

	for (double t = 1e6, alpha = 0.999; t > 1e-6;) {
		int dir = dis_dir(rnd);
		auto [dx, dy] = directions[dir];
		pll p = {best_point.first + dx, best_point.second + dy};

		if (p.first < 0 || p.first > n || p.second < 0 || p.second > m) {
			continue;
		}

		double dist = CalculateMinDistance(points, p);
		if (ShouldReplace(max_dist, dist, t)) {
			max_dist = dist;
			best_point = p;
		}

		t *= alpha;
	}

	return {best_point.first / (double)ZOOM, best_point.second / (double)ZOOM};
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		auto [x, y] = Solve();
		printf("The safest point is (%.1lf, %.1lf).\n", x, y);
	}
	return 0;
}