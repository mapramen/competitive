#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const vector<int> fermats_primes = {3, 5, 17, 257, 65537};
unordered_set<int> S;

void Initialize() {
	vector<int> v{1};
	for (int p : fermats_primes) {
		for (int n = v.size(), i = 0; i < n; ++i) {
			v.push_back(v[i] * p);
			S.insert(v.back());
		}
	}
}

bool Solve() {
	int n;
	scanf("%d", &n);

	if (n == 1) {
		return true;
	}

	while (n % 2 == 0) {
		n /= 2;
	}

	return n == 1 || S.find(n) != S.end();
}

int main() {
	Initialize();
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%s\n", Solve() ? "Yes" : "No");
	}
	return 0;
}