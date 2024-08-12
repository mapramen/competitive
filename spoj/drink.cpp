#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define SPECIFIC_HEAT_CAPACITY_OF_WATER 4.19
#define SPECIFIC_HEAT_CAPACITY_OF_ICE 2.09
#define LATENT_HEAT_OF_FUSION 335.0

tuple<double, double, double> Solve() {
	double mw, mi, tw, ti;
	scanf("%lf%lf%lf%lf", &mw, &mi, &tw, &ti);

	if (mw + mi == 0) {
		exit(0);
	}

	double m = mw + mi;
	double t = ti;
	double Q = mw * (SPECIFIC_HEAT_CAPACITY_OF_WATER * tw + LATENT_HEAT_OF_FUSION + SPECIFIC_HEAT_CAPACITY_OF_ICE * -ti);

	if (Q <= m * SPECIFIC_HEAT_CAPACITY_OF_ICE * -ti) {
		return {ti + Q / (m * SPECIFIC_HEAT_CAPACITY_OF_ICE), m, 0};
	}

	Q -= m * SPECIFIC_HEAT_CAPACITY_OF_ICE * -ti;

	if (Q <= m * LATENT_HEAT_OF_FUSION) {
		return {0, m - Q / LATENT_HEAT_OF_FUSION, Q / LATENT_HEAT_OF_FUSION};
	}

	Q -= m * LATENT_HEAT_OF_FUSION;

	return {Q / (m * SPECIFIC_HEAT_CAPACITY_OF_WATER), 0, m};
}

int main() {
	while (true) {
		auto [t, wi, ww] = Solve();
		printf("%.1lf g of ice and %.1lf g of water at %.1lf C\n", wi, ww, t);
	}
	return 0;
}