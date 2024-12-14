#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define NUMBER_OF_SECONDS 100
#define NUMBER_OF_QUADRANTS 5

pii CalculateFinalPosition(const int n, const int m, const int px, const int py, const int vx, const int vy) {
	int fx = (px + 1ll * vx * NUMBER_OF_SECONDS) % n;
	int fy = (py + 1ll * vy * NUMBER_OF_SECONDS) % m;

	if (fx < 0) {
		fx += n;
	}

	if (fy < 0) {
		fy += m;
	}

	return {fx, fy};
}

int CalculateQuadrant(const int n, const int m, const int x, const int y) {
	if (x == n / 2 || y == m / 2) {
		return 0;
	}

	if (x < n / 2 && y < m / 2) {
		return 1;
	}

	if (x < n / 2 && y > m / 2) {
		return 2;
	}

	if (x > n / 2 && y < m / 2) {
		return 3;
	}

	if (x > n / 2 && y > m / 2) {
		return 4;
	}

	assert(false);
}

int main() {
	int n, m;
	scanf("n=%d, m=%d\n", &n, &m);

	assert(n % 2 == 1 && m % 2 == 1);

	vector<int> cnt(NUMBER_OF_QUADRANTS);

	for (int px, py, vx, vy; scanf("p=%d,%d v=%d,%d\n", &px, &py, &vx, &vy) != EOF;) {
		auto [fx, fy] = CalculateFinalPosition(n, m, px, py, vx, vy);
		++cnt[CalculateQuadrant(n, m, fx, fy)];
	}

	ll ans = 1;
	for (int i = 1; i < NUMBER_OF_QUADRANTS; ++i) {
		ans *= cnt[i];
	}
	printf("%lld\n", ans);

	return 0;
}