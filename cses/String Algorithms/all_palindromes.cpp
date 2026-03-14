#include <bits/stdc++.h>

using namespace std;

vector<int> ManacherAlgorithmOddLength(string s) {
	const int n = s.size();
	vector<int> palindrome_widths(n);

	vector<int> d(n);
	for (int i = 0, l = 0, r = -1; i < n; ++i) {
		int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);

		while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
			++k;
		}

		d[i] = k--;
		if (i + k > r) {
			l = i - k, r = i + k;
		}

		palindrome_widths[i] = k;
	}

	return palindrome_widths;
}

int main() {
	string s;
	cin >> s;

	string t = "#";
	for (const char c : s) {
		t.push_back(c);
		t.push_back('#');
	}

	vector<int> palindrome_widths = ManacherAlgorithmOddLength(t);

	vector<int> dp(s.size());
	for (int i = 1; i < t.size() - 1; ++i) {
		const int d = palindrome_widths[i];
		if (d == 0) {
			continue;
		}

		const int r = (i / 2) + (d / 2) - (i % 2 == 0);
		dp[r] = max(dp[r], d);
	}

	for (int i = s.size() - 1; i > -1; --i) {
		dp[i] = max(dp[i], dp[i + 1] - 2);
	}

	for (const int& dpi : dp) {
		printf("%d ", dpi);
	}
	printf("\n");

	return 0;
}