#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define B 10

int Find(vector<int>& parent, const int i) {
	return parent[i] == i ? i : parent[i] = Find(parent, parent[i]);
}

int GetBucketNumber(const string& s, vector<int>& nxt, const int i) {
	if (i <= 0 || Find(nxt, i) != i) {
		return B;
	}

	const int d = s[i] - '0';

	const int j = Find(nxt, i + 1);
	// printf("s[%d] = %c s[%d] = %c\n", i, s[i], j, s[j]);
	return '0' + (d + 1) % B == s[j] ? d : B;
}

string Solve() {
	int n;
	string s;
	cin >> n >> s;

	s = "X" + s + "X";

	vector<int> prv(n + 2), nxt(n + 2);
	iota(prv.begin(), prv.end(), 0);
	iota(nxt.begin(), nxt.end(), 0);

	vector<vector<int>> V(B + 1);
	for (int i = 1; i <= n; ++i) {
		V[GetBucketNumber(s, nxt, i)].push_back(i);
	}

	for (int t = 0, last_update_t = 0; t - last_update_t <= B; ++t) {
		const int d = t % B;
		const vector<int> v(V[d]);

		V[d].clear();
		for (const int i : v) {
			if (GetBucketNumber(s, nxt, i) != d) {
				continue;
			}

			s[i] = '0' + (d + 2) % B;
			const int x = Find(prv, i - 1);
			const int y = Find(nxt, i + 1);
			prv[y] = i;
			nxt[y] = y + 1;

			V[GetBucketNumber(s, nxt, x)].push_back(x);
			V[GetBucketNumber(s, nxt, i)].push_back(i);
			last_update_t = t;
		}
	}

	string ans;
	for (int i = 1; i <= n; ++i) {
		if (Find(nxt, i) == i) {
			ans.push_back(s[i]);
		}
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}