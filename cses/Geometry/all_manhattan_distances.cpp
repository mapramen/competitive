#include <bits/stdc++.h>

using namespace std;

std::ostream& operator<<(std::ostream& os, __uint128_t x) {
	if (x == 0) return os << "0";

	std::string s;
	while (x > 0) {
		s += '0' + (x % 10);
		x /= 10;
	}
	std::reverse(s.begin(), s.end());
	return os << s;
}

__uint128_t solve(vector<int>& a) {
	const int n = a.size();

	sort(a.begin(), a.end());

	long long sum = 0;
	__uint128_t ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += 1ll * i * a[i] - sum;
		sum += a[i];
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> xs, ys;

	while (n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		xs.push_back(x);
		ys.push_back(y);
	}

	const auto ans = solve(xs) + solve(ys);
	cout << ans << '\n';

	return 0;
}