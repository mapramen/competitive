#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	vector<int> freq(k + 1);
	priority_queue<int, vector<int>, greater<int>> Q;

	for (int x = 0; x <= k; ++x) {
		Q.push(x);
	}

	for (int i = 0; i < n; ++i) {
		const int x = a[i];
		if (x <= k) {
			++freq[x];
		}

		if (i >= k) {
			const int y = a[i - k];
			if (y <= k) {
				--freq[y];
				Q.push(y);
			}
		}

		if (i < k - 1) {
			continue;
		}

		while (freq[Q.top()] != 0) {
			Q.pop();
		}

		printf("%d ", Q.top());
	}
	printf("\n");

	return 0;
}