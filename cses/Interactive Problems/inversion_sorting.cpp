#include <bits/stdc++.h>

using namespace std;

// Reverse the subarray [i, j] and return the number of inversions in the resulting array.
int MakeTurn(const int i, const int j) {
	printf("%d %d\n", i, j);
	fflush(stdout);

	int res;
	scanf("%d", &res);

	if (res == 0) {
		exit(0);
	}

	return res;
}

int GetInversionCount(const int i) {
	const int a = MakeTurn(1, i);
	const int b = MakeTurn(1, i);
	return (b - a + i * (i - 1) / 2) / 2;
}

void Exchange(const int i, const int j) {
	MakeTurn(i, j);
	MakeTurn(i + 1, j);
}

int main() {
	int n;
	scanf("%d", &n);

	if (n == 1) {
		GetInversionCount(1);
		return 0;
	}

	for (int i = 2; i <= n; ++i) {
		const int j = GetInversionCount(i);
		if (j == 0) {
			continue;
		}
		Exchange(i - j, i);
	}

	return 0;
}