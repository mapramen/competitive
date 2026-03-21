#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);

		long long a = n - 1;
		long long b = m - 1;
		long long g = gcd(a, b);

		// 1. Number of steps to return to the initial state
		long long S = 2 * (a / g) * b;

		// 2. Number of distinct cells visited
		long long A = a / g;
		long long B = b / g;

		long long v0 = (A / 2 + 1) * (B / 2 + 1) + ((A + 1) / 2) * ((B + 1) / 2);
		long long V = v0 + (g - 1) * A * B;

		cout << S << " " << V << "\n";
	}
	return 0;
}