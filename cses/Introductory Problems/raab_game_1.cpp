#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pair<vector<int>, vector<int>> Solve(const int n, const int a, const int b) {
	if (b < a) {
		const auto [A, B] = Solve(n, b, a);
		return {B, A};
	}

	vector<int> A(n);
	iota(A.begin(), A.end(), 1);
	vector<int> B(A);

	if (b == 0) {
		return {A, B};
	}

	if (a == 0 || a + b > n) {
		return {{}, {}};
	}

	for (int i = 1; i < a; ++i) {
		swap(B[2 * i - 2], B[2 * i - 1]);
	}

	const int x = 2 * a - 2, y = x + (b - a + 1);
	for (int z = y - 1; z >= x; --z) {
		swap(B[z], B[y]);
	}

	return {A, B};
}

pair<vector<int>, vector<int>> Solve() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	return Solve(n, a, b);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		const auto [a, b] = Solve();

		if (a.empty()) {
			printf("NO\n");
			continue;
		}

		printf("YES\n");

		for (const int x : a) {
			printf("%d ", x);
		}
		printf("\n");

		for (const int x : b) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}