#include <bits/stdc++.h>

using namespace std;

int GenerateNext(const int a, const int b, const int c, const int x) {
	return (1ll * a * x + b) % c;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	int x, a, b, c;
	scanf("%d%d%d%d", &x, &a, &b, &c);

	vector<int> A(k);
	A[0] = x;

	for (int i = 1; i < k; ++i) {
		x = GenerateNext(a, b, c, x);
		A[i] = x;
	}

	int sum = accumulate(A.begin(), A.end(), 0, bit_xor<int>());
	int ans = sum;

	for (int i = k; i < n; ++i) {
		const int j = i % k;

		sum ^= A[j];
		x = GenerateNext(a, b, c, x);
		A[j] = x;

		sum ^= A[j];
		ans ^= sum;
	}

	printf("%d\n", ans);

	return 0;
}