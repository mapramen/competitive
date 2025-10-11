#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

int freq[N];

vector<int> Solve() {
	int n;
	scanf("%d", &n);

	fill(freq, freq + N, 0);

	vector<int> ans;
	int i = 0, cnt = 0;
	while (n--) {
		int x;
		scanf("%d", &x);

		++freq[x];
		if (x >= i) {
			++cnt;
		}

		for (; i <= cnt; ++i) {
			cnt -= freq[i];
		}
		--i;
		cnt += freq[i];

		ans.push_back(i);
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