#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
	int n;
	scanf("%d", &n);

	string s;
	for (; n > 0; n /= 3) {
		if (n % 3 == 0) {
			s.push_back('0');
			continue;
		}

		if (n % 3 == 1) {
			s.push_back('+');
			continue;
		}

		s.push_back('-');
		n++;
	}

	if (s.empty()) {
		s.push_back('0');
	}

	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%s\n", Solve().c_str());
	}
	return 0;
}