#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 101

vector<int> Solve() {
	int x, y, a, b;
	scanf("%d%d%d%d", &x, &y, &a, &b);

	int c2 = a * a + b * b;

	vector<int> ans;
	while (ans.size() < N && (x != 0 || y != 0)) {
		int r = 0;
		for (; r * r < c2; ++r) {
			int nx = a * (x - r) + b * y;
			int ny = a * y - b * (x - r);
			if (nx % c2 == 0 && ny % c2 == 0) {
				x = nx / c2, y = ny / c2;
				break;
			}
		}

		if (r * r >= c2) {
			break;
		}

		ans.push_back(r);
	}

	if (ans.size() > N || x != 0 || y != 0) {
		return vector<int>();
	}

	ans.push_back(0);

	while (ans.size() > 1 && ans.back() == 0) {
		ans.pop_back();
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<int> ans = Solve();
		if (ans.empty()) {
			printf("The code cannot be decrypted.\n");
			continue;
		}

		reverse(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++) {
			if (i != 0) {
				printf(",");
			}
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}