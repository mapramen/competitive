#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define N 1001
#define B 30

int trie[N * B][2], indx[N * B], nxt = 1;

void Reset(int n) {
	for (int i = 0; i <= n * B; ++i) {
		trie[i][0] = trie[i][1] = 0;
		indx[i] = INT_MAX;
	}
}

void Insert(int x, int i) {
	int cur = 0;
	for (int j = B - 1; j >= 0; --j) {
		int b = (x >> j) & 1;
		if (trie[cur][b] == 0) {
			trie[cur][b] = nxt++;
		}
		cur = trie[cur][b];
	}
	indx[cur] = min(indx[cur], i);
}

pii Query(int x) {
	int cur = 0, s = 0;
	for (int j = B - 1; j >= 0; --j) {
		int b = (x >> j) & 1;
		if (trie[cur][b ^ 1] != 0) {
			cur = trie[cur][b ^ 1];
			s |= 1 << j;
		} else {
			cur = trie[cur][b];
		}
	}
	return {s, indx[cur] + 1};
}

int main() {
	int n;
	scanf("%d", &n);

	Reset(n);
	Insert(0, 0);

	tuple<int, int, int> ans = {INT_MIN, 0, 0};
	for (int j = 1, s = 0; j <= n; ++j) {
		int x;
		scanf("%d", &x);
		s ^= x;

		auto [ans_i, i] = Query(s);
		ans = max(ans, {ans_i, -i, -j});

		Insert(s, j);
	}

	printf("%d\n", get<0>(ans));
	printf("%d %d\n", -get<1>(ans), -get<2>(ans));

	return 0;
}