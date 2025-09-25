#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsPalindrome(const int n, const int mask) {
	for (int i = 0, j = n - 1; i < j; ++i, --j) {
		const int bi = (mask & (1 << i)) != 0;
		const int bj = (mask & (1 << j)) != 0;
		if (bi != bj) {
			return false;
		}
	}
	return true;
}

uint64_t CalculatePalindromicMask(const int n) {
	uint64_t palindromic_mask = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		if (IsPalindrome(n, mask)) {
			palindromic_mask |= (1ull << mask);
		}
	}
	return palindromic_mask;
}

int TruncateMask(const int n, const int mask) {
	return mask & ((1 << n) - 1);
}

bool IsPresent(const int n, const uint64_t palindromic_mask, const int mask) {
	const int i = TruncateMask(n, mask);
	return (palindromic_mask & (1ull << i)) != 0;
}

string Solve() {
	int n;
	string s;
	cin >> n >> s;

	const auto five_mask = CalculatePalindromicMask(5), six_mask = CalculatePalindromicMask(6);

	uint32_t string_mask = 1;

	for (int i = 1; i <= n && string_mask != 0; ++i) {
		const char c = s[i - 1];

		uint32_t new_string_mask = 0;
		while (string_mask != 0) {
			const int x = __builtin_ctz(string_mask);
			string_mask ^= (1u << x);

			for (int b = 0; b < 2; ++b) {
				if (c != '?' && c != '0' + b) {
					continue;
				}

				const int y = TruncateMask(6, (x << 1) + b);
				if ((i >= 5 && IsPresent(5, five_mask, y)) || (i >= 6 && IsPresent(6, six_mask, y))) {
					continue;
				}

				new_string_mask |= (1u << TruncateMask(5, y));
			}
		}

		string_mask = new_string_mask;
	}

	return string_mask == 0 ? "IMPOSSIBLE" : "POSSIBLE";
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}