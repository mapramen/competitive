#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	vector<int> b(a);
	sort(b.begin(), b.end());
	b.push_back(INT_MAX);

	vector<int> ans;
	for (const int x : a) {
		const int i = upper_bound(b.begin(), b.end(), 2 * x) - b.begin() - 1;
		ans.push_back(b[i] != x ? b[i] : (i == 0 ? -1 : b[i - 1]));
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d:", k);
		for (const int x : Solve()) {
			printf(" %d", x);
		}
		printf("\n");
	}
	return 0;
}