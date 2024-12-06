#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 4
#define N (1 << B)
#define M (1 << N)

int d[M];

void AddMoves(vector<pii>& moves, const int b, const int i) {
	if (b == 0) {
		return;
	}

	const int j = i + (1 << (b - 1));
	for (int k = 0; k < (1 << (b - 1)); ++k) {
		moves.push_back({i + k, j + k});
	}

	AddMoves(moves, b - 1, i);
	AddMoves(moves, b - 1, j);
}

void CheckAndPush(queue<int>& Q, int i, int di) {
	if (di >= d[i]) {
		return;
	}

	d[i] = di;
	Q.push(i);
}

int CalculateNextState(int i, int k1, int k2) {
	int x = (i >> k1) & 1;
	int y = (i >> k2) & 1;
	return i ^ ((x ^ y) << k1) ^ ((x ^ y) << k2);
}

void Initialize() {
	queue<int> Q;

	vector<pii> moves;
	AddMoves(moves, B, 0);

	for (int i = 0; i < M; ++i) {
		d[i] = INT_MAX;
	}

	CheckAndPush(Q, ((1 << N) - 1) ^ ((1 << (N / 2)) - 1), 0);

	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();

		int di = d[i];
		for (auto [k1, k2] : moves) {
			CheckAndPush(Q, CalculateNextState(i, k1, k2), di + 1);
		}
	}
}

int Solve() {
	int i = 0;
	for (int k = 0; k < N; ++k) {
		int x;
		scanf("%d", &x);
		i |= (x << k);
	}

	return d[i];
}

int main() {
	Initialize();

	int t;
	scanf("%d", &t);

	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: ", k);
		int ans = Solve();
		if (ans < 4) {
			printf("%d\n", ans);
		} else {
			printf("more\n");
		}
	}

	return 0;
}