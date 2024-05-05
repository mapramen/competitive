#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double Solve() {
	int n;
	scanf("%d", &n);
	return 2 + 1.0 / n;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%.8f\n", Solve());
	}
	return 0;
}