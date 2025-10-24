#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int GetMedian(vector<int>& a) {
	const int n = a.size();
	assert(n % 2 == 0);

	nth_element(a.begin(), a.begin() + (n / 2) - 1, a.end());

	const int ans = a[(n / 2) - 1];
	a.clear();

	return ans;
}

pii Solve() {
	int n;
	scanf("%d", &n);

	vector<int> X, Y;
	while (n--) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		X.push_back(x1), X.push_back(x2);
		Y.push_back(y1), Y.push_back(y2);
	}

	return {GetMedian(X), GetMedian(Y)};
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		auto [x, y] = Solve();
		printf("Case #%d: %d %d\n", k, x, y);
	}
	return 0;
}