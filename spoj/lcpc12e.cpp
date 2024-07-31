#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double Distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Solve() {
	double x1, y1, x2, y2, r1, l;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &r1, &l);

	double r2 = l / sqrt(2);

	double d = Distance(x1, y1, x2, y2);

	if (d >= r1 + r2) {
		return 0.0;
	}

	double x = (r1 * r1 - r2 * r2 + d * d) / (2 * d);

	return 2 * sqrt(r1 * r1 - x * x);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		double ans = Solve();
		if (ans == 0.0) {
			printf("%d. No problem\n", k);
			continue;
		}

		printf("%d. %.3lf\n", k, ans);
	}
	return 0;
}