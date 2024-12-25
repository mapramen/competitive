#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 4
#define M 6

int main() {
	vector<int> a(N);

	bool found = false;
	for (int x = 1; x <= M && !found; ++x) {
		for (int i = 0; i < N; ++i) {
			if (i != 0) {
				cout << " ";
			}
			cout << x;
		}
		cout << endl;
		fflush(stdout);

		found = true;
		for (int i = 0; i < N; ++i) {
			int y;
			cin >> y;
			if (y == 1) {
				a[i] = x;
			} else {
				found = false;
			}
		}
	}

	if (!found) {
		for (int i = 0; i < N; ++i) {
			if (i != 0) {
				cout << " ";
			}
			cout << a[i];
		}
		cout << endl;
		fflush(stdout);
	}

	return 0;
}