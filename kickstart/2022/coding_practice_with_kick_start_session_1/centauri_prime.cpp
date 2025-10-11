#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsVowel(const char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string GetRuler(const string& s) {
	const char c = tolower(s.back());

	if (c == 'y') {
		return "nobody";
	}

	return IsVowel(c) ? "Alice" : "Bob";
}

string Solve() {
	string s;
	cin >> s;
	return s + " is ruled by " + GetRuler(s) + ".";
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}