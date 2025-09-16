#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> ReadStones(const int rh, const int rs) {
	int n;
	scanf("%d", &n);

	const int threshold = (rh + rs) * (rh + rs);

	vector<int> distances{INT_MAX};
	while (n--) {
		int x, y;
		scanf("%d%d", &x, &y);

		const int d = x * x + y * y;
		if (d <= threshold) {
			distances.push_back(d);
		}
	}
	return distances;
}

int CalculatePoints(const vector<int>& distances, const int threshold) {
	return accumulate(distances.begin(), distances.end(), 0, [&](const int acc, const int d) { return acc + (d < threshold); });
}

pii Solve() {
	int rs, rh;
	scanf("%d%d", &rs, &rh);

	const auto distances1 = ReadStones(rh, rs);
	const auto distances2 = ReadStones(rh, rs);

	const int min_distance1 = *min_element(distances1.begin(), distances1.end());
	const int min_distance2 = *min_element(distances2.begin(), distances2.end());

	if (min_distance1 < min_distance2) {
		return {CalculatePoints(distances1, min_distance2), 0};
	}

	return {0, CalculatePoints(distances2, min_distance1)};
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		auto [score1, score2] = Solve();
		printf("Case #%d: %d %d\n", k, score1, score2);
	}
	return 0;
}