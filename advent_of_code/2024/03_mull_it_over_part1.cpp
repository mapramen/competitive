#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
	ll ans = 0;

	for (string s; getline(cin, s);) {
		regex rx("mul\\((\\d{1,3}),(\\d{1,3})\\)");
		for (sregex_iterator it(s.begin(), s.end(), rx), end_it; it != end_it; ++it) {
			ans += 1ll * stoi((*it)[1].str()) * stoi((*it)[2].str());
		}
	}

	printf("%lld\n", ans);

	return 0;
}