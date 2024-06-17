#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int GetNext(int n) {
	int s = 0;
	for (; n > 0; n /= 10) {
		int d = n % 10;
		s += d * d;
	}
	return s;
}

map<int, int> GetCycleMap(int n) {
	map<int, int> M;

	int i = 1;
	while (M.count(n) == 0) {
		M[n] = i;

		n = GetNext(n);
		++i;
	}

	return M;
}

void Solve() {
	int a, b;
	scanf("%d%d", &a, &b);

	if (a == 0 && b == 0) {
		exit(0);
	}

	map<int, int> M1 = GetCycleMap(a);
	map<int, int> M2 = GetCycleMap(b);

	int ans = INT_MAX;
	for (auto [k1, v1] : M1) {
		auto it = M2.find(k1);
		if (it == M2.end()) {
			continue;
		}
		ans = min(ans, v1 + it->second);
	}

	if (ans == INT_MAX) {
		ans = 0;
	}

	printf("%d %d %d\n", a, b, ans);
}

int main() {
	while (true) {
		Solve();
	}
	return 0;
}