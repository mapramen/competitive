#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

char s[N];

int ReadIntMod2() {
	scanf("%s", s);
	return (string(s).back() - '0') % 2;
}

bool Solve() {
	int n = ReadIntMod2();
	int m = ReadIntMod2();

	int x = ReadIntMod2();
	int y = ReadIntMod2();

	return (n * m) % 2 == 1 && (x + y) % 2 == 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%s.\n", Solve() ? "Possible" : "Impossible");
	}
	return 0;
}