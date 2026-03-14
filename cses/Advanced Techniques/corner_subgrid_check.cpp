#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 3000

int seen[N][N];

bool check(const vector<string>& s, const char target) {
	const int n = s.size();

	for (int i = 0; i < n; ++i) {
		vector<int> a;

		for (int j = 0; j < n; ++j) {
			if (s[i][j] == target) {
				a.push_back(j);
			}
		}

		for (int x = 0; x < a.size(); ++x) {
			for (int y = x + 1; y < a.size(); ++y) {
				if (seen[a[x]][a[y]] == target) {
					return true;
				}
			}
		}

		for (int x = 0; x < a.size(); ++x) {
			for (int y = x + 1; y < a.size(); ++y) {
				seen[a[x]][a[y]] = target;
			}
		}
	}

	return false;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			seen[i][j] = -1;
		}
	}

	for (int b = 0; b < k; ++b) {
		printf("%s\n", check(s, 'A' + b) ? "YES" : "NO");
	}

	return 0;
}