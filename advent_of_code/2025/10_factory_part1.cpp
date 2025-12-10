#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pii ExtractTargetMask(string& s) {
	reverse(s.begin(), s.end());

	//[....
	s.pop_back();

	int n = 0, mask = 0;
	for (int i = 0; s.back() != ']'; ++i, s.pop_back()) {
		if (s.back() == '#') {
			mask |= (1 << i);
		}
		++n;
	}

	//] ....
	s.pop_back();
	s.pop_back();

	reverse(s.begin(), s.end());
	return {n, mask};
}

int ExtractNumber(string& s) {
	// n,...
	// n)...

	int x = 0;
	for (; isdigit(s.back()); s.pop_back()) {
		x = 10 * x + (s.back() - '0');
	}

	//,...
	//)...
	s.pop_back();

	return x;
}

int ExtractButtonMask(string& s) {
	reverse(s.begin(), s.end());

	//(
	s.pop_back();

	int mask = 0;
	while (s.back() != ' ') {
		const int i = ExtractNumber(s);
		mask |= (1 << i);
	}

	// ...
	s.pop_back();

	reverse(s.begin(), s.end());
	return mask;
}

int Solve(string s) {
	const auto [n, target_mask] = ExtractTargetMask(s);

	vector<int> dp((1 << n), INT_MAX / 2);
	dp[0] = 0;

	while (s.front() != '{') {
		const int button_mask = ExtractButtonMask(s);

		for (int i = 0; i < (1 << n); ++i) {
			dp[(i ^ button_mask)] = min(dp[(i ^ button_mask)], 1 + dp[i]);
		}
	}

	return dp[target_mask];
}

int main() {
	int ans = 0;
	for (string s; getline(cin, s);) {
		ans += Solve(s);
	}
	cout << ans << '\n';
	return 0;
}