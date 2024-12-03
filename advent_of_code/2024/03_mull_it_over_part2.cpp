#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
	ll ans = 0;
	bool do_multiplication = true;

	for (string s; getline(cin, s);) {
		regex rx("(mul\\((\\d{1,3}),(\\d{1,3})\\)|do\\(\\)|don't\\(\\))");

		for (sregex_iterator it(s.begin(), s.end(), rx), end_it; it != end_it; ++it) {
			if ((*it)[0] == "do()") {
				do_multiplication = true;
				continue;
			}

			if ((*it)[0] == "don't()") {
				do_multiplication = false;
				continue;
			}

			if (do_multiplication) {
				ans += 1ll * stoi((*it)[2].str()) * stoi((*it)[3].str());
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}