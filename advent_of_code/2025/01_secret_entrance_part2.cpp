#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define M 100

int CalculatePos(const int pos, const int x) {
	return (pos + M + (x % M)) % M;
}

int main() {
	int ans = 0;

	int pos = 50;
	for (string s; getline(cin, s);) {
		const char direction = s[0];
		int x = stoi(s.substr(1));

		if (direction == 'L') {
			if (pos != 0 && x >= pos) {
				x -= pos;
				pos = 0;
				++ans;
			}

			ans += (x / M);
			pos = CalculatePos(pos, -x);
		} else {
			if (pos != 0 && pos + x >= M) {
				x -= (M - pos);
				pos = 0;
				++ans;
			}

			ans += (x / M);
			pos = CalculatePos(pos, x);
		}

		// printf("%s pos = %d ans = %d\n", s.c_str(), pos, ans);
	}

	cout << ans << '\n';

	return 0;
}