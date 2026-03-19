#include <bits/stdc++.h>

using namespace std;

int Query(const int y) {
	cout << "? " << y << "\n";
	fflush(stdout);

	string s;
	cin >> s;
	return s[0] == 'R';
}

void PrintAns(const int x) {
	cout << "! " << x << "\n";
	fflush(stdout);
}

int main() {
	int n;
	cin >> n;

	const int color1 = Query(1);
	if (Query(2) == color1) {
		PrintAns(1);
		return 0;
	}

	int l = 2, r = n + 1;
	while (r - l > 1) {
		const int mid = l + (r - l) / 2;
		const int expected_color = ((mid - 1) % 2) ^ color1;
		if (Query(mid) == expected_color) {
			l = mid;
		} else {
			r = mid;
		}
	}

	PrintAns(l);

	return 0;
}