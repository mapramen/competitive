#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
	int n;
	scanf("%d", &n);

	vector<int> ans;

	priority_queue<int, vector<int>, greater<int>> Q;
	while (n--) {
		int x;
		scanf("%d", &x);
		Q.push(x);

		while (Q.top() < Q.size()) {
			Q.pop();
		}

		ans.push_back(Q.size());
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