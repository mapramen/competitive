#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

vector<int> IntToVec(ull n) {
	vector<int> v;
	while (n) {
		v.push_back(n % 10);
		n /= 10;
	}
	reverse(v.begin(), v.end());
	return v;
}

int CalculateNewMask(int mask, int d) {
	mask |= (1 << (2 * d));
	mask ^= (2 << (2 * d));
	return mask;
}

bool IsMaskValid(int mask) {
	for (int d = 0; d < 10; ++d) {
		if ((mask & (1 << (2 * d))) == 0) {
			continue;
		}

		if ((d % 2 != 0) == ((mask & (2 << (2 * d))) != 0)) {
			return false;
		}
	}
	return true;
}

ull Calculate(ull n) {
	if (n == 0) {
		return 0;
	}

	vector<int> v = IntToVec(n);
	int len = v.size();

	unordered_map<int, ull> dp_cur, dp_next;

	for (int d = 1; d < v[0]; ++d) {
		dp_cur[CalculateNewMask(0, d)] = 1;
	}

	int equal_num_mask = CalculateNewMask(0, v[0]);
	for (int i = 1; i < len; ++i) {
		dp_next.clear();

		for (auto [mask, val] : dp_cur) {
			for (int d = 0; d < 10; ++d) {
				dp_next[CalculateNewMask(mask, d)] += val;
			}
		}

		for (int d = 0; d < v[i]; ++d) {
			dp_next[CalculateNewMask(equal_num_mask, d)] += 1;
		}

		for (int d = 1; d < 10; ++d) {
			dp_next[CalculateNewMask(0, d)] += 1;
		}

		dp_cur = dp_next;

		equal_num_mask = CalculateNewMask(equal_num_mask, v[i]);
	}

	ull ans = IsMaskValid(equal_num_mask) ? 1 : 0;
	for (auto [mask, val] : dp_cur) {
		if (IsMaskValid(mask)) {
			ans += val;
		}
	}

	return ans;
}

ull Solve() {
	ull a, b;
	scanf("%llu%llu", &a, &b);
	return Calculate(b) - Calculate(a - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%llu\n", Solve());
	}
	return 0;
}