#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define M 5002

int s[M];

vector<int> Solve() {
	int n;
	scanf("%d", &n);

	fill(s, s + M, 0);

	while (n--) {
		int l, r;
		scanf("%d%d", &l, &r);
		++s[l], --s[r + 1];
	}

	for (int i = 1; i < M; ++i) {
		s[i] += s[i - 1];
	}

	int q;
	scanf("%d", &q);

	vector<int> ans;
	while (q--) {
		int i;
		scanf("%d", &i);
		ans.push_back(s[i]);
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d:", k);
		for (int x : Solve()) {
			printf(" %d", x);
		}
		printf("\n");
	}
	return 0;
}