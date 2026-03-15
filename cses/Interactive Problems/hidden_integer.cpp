#include <bits/stdc++.h>

using namespace std;

map<int, bool> cache;

bool Query(const int y) {
	if (cache.count(y)) {
		return cache[y];
	}

	cout << "? " << y << "\n";
	fflush(stdout);

	string s;
	cin >> s;
	return cache[y] = (s == "YES");
}

void PrintAns(const int x) {
	cout << "! " << x << "\n";
	fflush(stdout);
}

int main() {
	int l = 1, r = 1E9;

	while (l < r) {
		const int mid = l + (r - l) / 2;
		if (Query(mid)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}

	PrintAns(l);

	return 0;
}