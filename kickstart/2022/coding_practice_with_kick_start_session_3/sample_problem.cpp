#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	int s = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		s += x;
	}
	return s % m;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}