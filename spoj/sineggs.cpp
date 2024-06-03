#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsSquareNumber(ll n) {
	ll x = sqrt(n) - 1;
	while (x * x < n) {
		++x;
	}
	return x * x == n;
}

bool Solve() {
	ll n;
	scanf("%lld", &n);
	return IsSquareNumber(n);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%s\n", Solve() ? "YES" : "NO");
	}
	return 0;
}