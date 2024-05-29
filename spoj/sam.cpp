#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n, k, p;
	scanf("%d%d%d", &n, &k, &p);

	vector<int> a(p + 1);

	for (int i = 1; i <= p; ++i) {
		scanf("%d", &a[i]);
	}

	vector<vector<int>> V(n + 1, vector<int>(1, p + 1));
	for (int i = p; i > 0; --i) {
		V[a[i]].push_back(i);
	}

	priority_queue<pii> Q;
	vector<bool> is_on_the_floor(n + 1);

	int ans = 0;
	for (int i = 1; i <= p; ++i) {
		int x = a[i];
		V[x].pop_back();

		if (!is_on_the_floor[x]) {
			if (k == 0) {
				while (V[Q.top().second].back() != Q.top().first) {
					Q.pop();
				}

				auto [_, y] = Q.top();
				Q.pop();
				is_on_the_floor[y] = false;
				++k;
			}
			--k, ++ans;
			is_on_the_floor[x] = true;
		}

		Q.push({V[x].back(), x});
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}