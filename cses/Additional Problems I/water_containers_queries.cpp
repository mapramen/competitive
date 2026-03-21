#include <bits/stdc++.h>

using namespace std;

bool Solve() {
	int a, b, x;
	scanf("%d%d%d", &a, &b, &x);

	return x <= a && x % __gcd(a, b) == 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%s\n", Solve() ? "YES" : "NO");
	}
	return 0;
}