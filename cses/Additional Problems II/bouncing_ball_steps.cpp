#include <bits/stdc++.h>

using namespace std;

int GetCoordinate(const int n, const long long k) {
	const int r = k % (2 * (n - 1));
	return r < n ? r + 1 : 2 * n - r - 1;
}

long long LCM(const int a, const int b) {
	return 1ll * a * b / gcd(a, b);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		long long k;
		scanf("%d%d%lld", &n, &m, &k);

		const int x = GetCoordinate(n, k);
		const int y = GetCoordinate(m, k);
		const auto bounces = k / (n - 1) + k / (m - 1) - k / LCM(n - 1, m - 1);
		printf("%d %d %lld\n", x, y, bounces);
	}

	return 0;
}