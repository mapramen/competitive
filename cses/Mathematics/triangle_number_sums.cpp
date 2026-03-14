#include <bits/stdc++.h>

using namespace std;

#define M 1E12

vector<long long> triangular_numbers;

void Initialize() {
	for (long long i = 1, s = 1; s <= M; ++i, s += i) {
		triangular_numbers.push_back(s);
	}
}

int Solve() {
	long long n;
	scanf("%lld", &n);

	if (*lower_bound(triangular_numbers.begin(), triangular_numbers.end(), n) == n) {
		return 1;
	}

	for (int i = 0, j = triangular_numbers.size() - 1; i <= j;) {
		if (triangular_numbers[i] + triangular_numbers[j] == n) {
			return 2;
		}

		if (triangular_numbers[i] + triangular_numbers[j] > n) {
			--j;
		} else {
			++i;
		}
	}

	return 3;
}

int main() {
	Initialize();

	int t;
	scanf("%d", &t);

	while (t--) {
		printf("%d\n", Solve());
	}

	return 0;
}