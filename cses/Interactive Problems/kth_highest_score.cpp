#include <bits/stdc++.h>

using namespace std;

int Query(const int n, const char c, const int i) {
	if (i == 0) {
		return INT_MAX;
	}

	if (i > n) {
		return INT_MIN;
	}

	cout << c << " " << i << "\n";
	fflush(stdout);

	int x;
	cin >> x;
	return x;
}

void PrintAns(const int x) {
	cout << "! " << x << "\n";
	fflush(stdout);
}

int main() {
	int n, k;
	cin >> n >> k;

	int ans = 1;
	for (int low = 0, high = min(k, n); low <= high;) {
		const int mid = low + (high - low) / 2;

		if (Query(n, 'S', k - mid) >= Query(n, 'F', mid + 1)) {
			ans = mid, high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	PrintAns(min(Query(n, 'F', ans), Query(n, 'S', k - ans)));

	return 0;
}