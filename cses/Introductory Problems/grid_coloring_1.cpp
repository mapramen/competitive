#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<string> S(n);
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int mask = (1 << 4) - 1;

			mask &= ~(1 << (S[i][j] - 'A'));

			if (i != 0) {
				mask &= ~(1 << (S[i - 1][j] - 'A'));
			}

			if (j != 0) {
				mask &= ~(1 << (S[i][j - 1] - 'A'));
			}

			S[i][j] = 'A' + __builtin_ctz(mask);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << S[i] << "\n";
	}

	return 0;
}