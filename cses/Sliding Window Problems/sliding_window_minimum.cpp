#include <bits/stdc++.h>

using namespace std;

int GenerateNext(const int a, const int b, const int c, const int x) {
	return (1ll * a * x + b) % c;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	int x, a, b, c;
	scanf("%d%d%d%d", &x, &a, &b, &c);

	deque<pair<int, int>> Q;
	Q.push_back({x, 0});

	int ans = k == 1 ? x : 0;

	for (int i = 1; i < n; ++i) {
		x = GenerateNext(a, b, c, x);

		while (!Q.empty() && Q.back().first >= x) {
			Q.pop_back();
		}
		Q.push_back({x, i});

		while (i - Q.front().second >= k) {
			Q.pop_front();
		}

		if (i >= k - 1) {
			ans ^= Q.front().first;
		}
	}

	printf("%d\n", ans);

	return 0;
}