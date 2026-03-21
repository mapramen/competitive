#include <bits/stdc++.h>

using namespace std;

pair<double, int> solve(const vector<int>& a, const double target) {
	double mx = numeric_limits<double>::lowest(), sum = 0;
	int idx = -1;

	for (int i = 1; i < a.size(); ++i) {
		sum += (a[i] - target);
		if (sum > mx) {
			mx = sum;
			idx = i;
		}
	}
	return {mx, idx};
}

pair<int, int> solve(const vector<int>& a, const vector<int>& b, const double target) {
	const auto [sum1, idx1] = solve(a, target);
	const auto [sum2, idx2] = solve(b, target);
	return sum1 + sum2 > 0 ? make_pair(idx1, idx2) : make_pair(-1, -1);
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	vector<int> b(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}

	pair<int, int> ans = {1, 1};

	for (double x = (a[1] + b[1]) / 2.0, y = numeric_limits<double>::max(); y - x > 1e-6;) {
		const double mid = x + (y - x) / 2.0;
		const auto [idx1, idx2] = solve(a, b, mid);
		if (idx1 != -1) {
			ans = {idx1, idx2};
			x = mid;
		} else {
			y = mid;
		}
	}

	printf("%d %d\n", ans.first, ans.second);

	return 0;
}