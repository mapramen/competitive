#include <bits/stdc++.h>

using namespace std;

const vector<vector<int>> beautiful_permutations = {
		{},
		{1},
		{},
		{},
		{2, 4, 1, 3},
		{1, 3, 5, 2, 4},
		{1, 3, 5, 2, 4, 6},
		{1, 3, 5, 2, 6, 4, 7},
		{1, 3, 5, 2, 6, 8, 4, 7},
		{1, 3, 5, 2, 4, 7, 9, 6, 8},
};

int main() {
	int n;
	scanf("%d", &n);

	if (n < beautiful_permutations.size()) {
		if (beautiful_permutations[n].empty()) {
			printf("NO SOLUTION\n");
		} else {
			for (const int& x : beautiful_permutations[n]) {
				printf("%d ", x);
			}
			printf("\n");
		}

		return 0;
	}

	const int p = n / 5;
	for (int i = 1; i < p; ++i) {
		for (const int x : beautiful_permutations[5]) {
			printf("%d ", 5 * (i - 1) + x);
		}
	}

	for (const int x : beautiful_permutations[5 + n % 5]) {
		printf("%d ", 5 * (p - 1) + x);
	}
	printf("\n");

	return 0;
}