#include <bits/stdc++.h>

using namespace std;

int Solve() {
	int x, y;
	scanf("%d%d", &x, &y);
	--x, --y;

	if (x < y) {
		swap(x, y);
	}

	if (x == 0 && y == 0) {
		return 0;
	}

	if ((x == 2 && y == 2) || (x == 1 && y == 1)) {
		return 4;
	}

	if (x == 1 && y == 0) {
		return 3;
	}

	int d = max(max((x + 1) / 2, (y + 1) / 2), (x + y + 2) / 3);

	if (d % 2 != (x + y) % 2) {
		++d;
	}

	return d;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}