#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
	vector<int> A, B;

	for (int a, b; scanf("%d%d", &a, &b) != EOF;) {
		A.push_back(a);
		B.push_back(b);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	long long ans = 0;
	for (int i = 0; i < A.size(); i++) {
		ans += abs(A[i] - B[i]);
	}

	printf("%lld\n", ans);

	return 0;
}