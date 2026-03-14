#include <bits/stdc++.h>

using namespace std;

#define N 10000001

pair<int, int> sum_of_two_squares[N];

vector<int> Solve() {
	int n;
	scanf("%d", &n);

	for (int i = 0, j = n; i <= j; ++i, --j) {
		if (sum_of_two_squares[i].first == INT_MIN || sum_of_two_squares[j].first == INT_MIN) {
			continue;
		}

		const auto [a, b] = sum_of_two_squares[i];
		const auto [c, d] = sum_of_two_squares[j];
		return {a, b, c, d};
	}

	assert(false);
}

int main() {
	for (int i = 0; i < N; ++i) {
		sum_of_two_squares[i] = {INT_MIN, INT_MIN};
	}

	for (int i = 0; i * i < N; ++i) {
		for (int j = 0; i * i + j * j < N; ++j) {
			sum_of_two_squares[i * i + j * j] = {i, j};
		}
	}

	int t;
	scanf("%d", &t);
	while (t--) {
		for (int x : Solve()) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}