#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t, n, m, a;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		m = n * n + 1, a = n;
		for (; m % a != 0; --a);
		printf("%lld\n", 2 * n + a + m / a);
	}
	return 0;
}