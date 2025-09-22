#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void CheckAndFix(
		string& s,
		function<bool(char)> is_present,
		const char d) {
	for (const char& c : s) {
		if (is_present(c)) {
			return;
		}
	}
	s.push_back(d);
}

string Solve() {
	int n;
	string s;
	cin >> n >> s;

	CheckAndFix(s, [](const char c) { return isalpha(c) && isupper(c); }, 'A');
	CheckAndFix(s, [](const char c) { return isalpha(c) && islower(c); }, 'a');
	CheckAndFix(s, [](const char c) { return isdigit(c); }, '0');
	CheckAndFix(s, [](const char c) { return c == '#' || c == '@' || c == '*' || c == '&'; }, '#');

	while (s.size() < 7) {
		s.push_back('#');
	}

	return s;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}