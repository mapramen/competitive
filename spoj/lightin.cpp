#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int CalculateIntersectionX(vector<int>& a, int i, int j) {
	int n = a.size();
	if (a[i] >= a[j]) {
		return n + 1;
	}

	if (a[i] + sqrt(j - i) <= a[j]) {
		return j;
	}

	int x = j, y = n, ans = j;
	while (x <= y) {
		int mid = (x + y) / 2;
		if (a[i] + sqrt(mid - i) >= a[j] + sqrt(mid - j)) {
			ans = mid + 1, x = mid + 1;
		} else {
			y = mid - 1;
		}
	}
	return ans;
}

vector<int> Calculate(vector<int>& a) {
	int n = a.size();
	deque<int> Q;

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		while (!Q.empty()) {
			int x = CalculateIntersectionX(a, Q.back(), i);
			if (x >= n) {
				break;
			}

			if (Q.size() == 1 || CalculateIntersectionX(a, Q[Q.size() - 2], Q.back()) < x) {
				Q.push_back(i);
				break;
			}

			Q.pop_back();
		}

		if (Q.empty()) {
			Q.push_back(i);
		}

		while (Q.size() > 1 && CalculateIntersectionX(a, Q[0], Q[1]) <= i) {
			Q.pop_front();
		}

		int j = Q.front();
		ans[i] = a[j] + int(ceil(sqrt(i - j)));
	}

	return ans;
}

vector<int> Solve() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	vector<int> prefix_ans = Calculate(a);

	reverse(a.begin(), a.end());
	vector<int> suffix_ans = Calculate(a);
	reverse(suffix_ans.begin(), suffix_ans.end());
	reverse(a.begin(), a.end());

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i] = max(0, max(prefix_ans[i], suffix_ans[i]) - a[i]);
	}
	return ans;
}

int main() {
	int t = 1;
	while (t--) {
		for (int x : Solve()) {
			printf("%d\n", x);
		}
	}
	return 0;
}