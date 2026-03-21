#include <bits/stdc++.h>

using namespace std;

#define N 1000001

int T[N];

void Reset() {
	for (int i = 0; i < N; i++) {
		T[i] = -2 * N;
	}
}

void Update(int i, const int val) {
	for (; i < N; i += (i & -i)) {
		T[i] = max(T[i], val);
	}
}

int Query(int i) {
	int ans = -2 * N;
	for (; i > 0; i -= (i & -i)) {
		ans = max(ans, T[i]);
	}
	return ans;
}

void UpdateAns(vector<tuple<int, int, int>>& campsites, vector<int>& qans) {
	Reset();
	sort(campsites.begin(), campsites.end());
	for (auto& [x, y, k] : campsites) {
		if (k == -1) {
			Update(y, x + y);
		} else {
			qans[k] = min(qans[k], x + y - Query(y));
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<tuple<int, int, int>> campsites;
	while (n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		campsites.push_back({x, y, -1});
	}

	for (int k = 0; k < m; k++) {
		int x, y;
		scanf("%d%d", &x, &y);
		campsites.push_back({x, y, k});
	}

	vector<int> qans(m, INT_MAX);

	for (int flip_x = 0; flip_x < 2; ++flip_x) {
		for (int flip_y = 0; flip_y < 2; ++flip_y) {
			UpdateAns(campsites, qans);

			for (auto& t : campsites) {
				get<1>(t) = N - get<1>(t);
			}
		}

		for (auto& t : campsites) {
			get<0>(t) = N - get<0>(t);
		}
	}

	for (const auto ans : qans) {
		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}