#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	long long min_x_plus_y = INT_MAX, max_x_plus_y = INT_MIN;
	long long min_x_minus_y = INT_MAX, max_x_minus_y = INT_MIN;

	long long ans = 0;
	while (n--) {
		int x, y;
		scanf("%d%d", &x, &y);

		const long long x_plus_y = x + y, x_minus_y = x - y;

		min_x_plus_y = min(min_x_plus_y, x_plus_y);
		max_x_plus_y = max(max_x_plus_y, x_plus_y);

		min_x_minus_y = min(min_x_minus_y, x_minus_y);
		max_x_minus_y = max(max_x_minus_y, x_minus_y);

		ans = max(ans, max(max_x_plus_y - x_plus_y, x_plus_y - min_x_plus_y));
		ans = max(ans, max(max_x_minus_y - x_minus_y, x_minus_y - min_x_minus_y));

		printf("%lld\n", ans);
	}

	return 0;
}