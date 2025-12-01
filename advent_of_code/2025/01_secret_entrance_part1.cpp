#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define M 100

int main() {
	int ans = 0;

	int pos = 50;
	for (string s; getline(cin, s);) {
		const int x = stoi(s.substr(1));
		pos = (pos + (s[0] == 'R' ? x : (M - x))) % M;
		ans += (pos == 0);
	}

	cout << ans << '\n';

	return 0;
}