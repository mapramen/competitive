#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Distance(int n, int i, int j) {
	return min(abs(i - j), n - abs(i - j));
}

int ModularIncrement(int n, int i) {
	return (i + 1) % n;
}

int ModularDecrement(int n, int i) {
	return (i - 1 + n) % n;
}

int LeftCost(vector<int>& ball_position, vector<int>& left_position, vector<int>& right_position, int n, int m, int i) {
	int j = ModularDecrement(m, i);
	int cost = Distance(n, ball_position[i], ModularDecrement(n, left_position[i]));

	if (right_position[j] != ModularDecrement(n, left_position[i])) {
		return cost;
	}

	cost -= Distance(n, ball_position[j], right_position[j]);
	return cost + LeftCost(ball_position, left_position, right_position, n, m, j);
}

int RightCost(vector<int>& ball_position, vector<int>& left_position, vector<int>& right_position, int n, int m, int i) {
	int j = ModularIncrement(m, i);
	int cost = Distance(n, ball_position[i], ModularIncrement(n, right_position[i]));

	if (left_position[j] != ModularIncrement(n, right_position[i])) {
		return cost;
	}

	cost -= Distance(n, ball_position[j], left_position[j]);
	return cost + RightCost(ball_position, left_position, right_position, n, m, j);
}

void PutToLeft(vector<int>& ball_position, vector<int>& left_position, vector<int>& right_position, int n, int m, int i) {
	int j = ModularDecrement(m, i);
	left_position[i] = ModularDecrement(n, left_position[i]);

	if (right_position[j] != left_position[i]) {
		return;
	}

	right_position[j] = ModularDecrement(n, right_position[j]);
	PutToLeft(ball_position, left_position, right_position, n, m, j);
}

void PutToRight(vector<int>& ball_position, vector<int>& left_position, vector<int>& right_position, int n, int m, int i) {
	int j = ModularIncrement(m, i);
	right_position[i] = ModularIncrement(n, right_position[i]);

	if (left_position[j] != right_position[i]) {
		return;
	}

	left_position[j] = ModularIncrement(n, left_position[j]);
	PutToRight(ball_position, left_position, right_position, n, m, j);
}

int Solve() {
	int n;
	scanf("%d", &n);

	vector<int> ball_position, ball_count;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);

		if (x != 0) {
			ball_position.push_back(i);
			ball_count.push_back(x - 1);
		}
	}

	int m = ball_position.size();
	vector<int> left_position(ball_position), right_position(ball_position);

	for (int i = 0; i < m; ++i) {
		int k = ball_count[i];
		while (k--) {
			int left_cost = LeftCost(ball_position, left_position, right_position, n, m, i);
			int right_cost = RightCost(ball_position, left_position, right_position, n, m, i);
			if (left_cost < right_cost) {
				PutToLeft(ball_position, left_position, right_position, n, m, i);
			} else {
				PutToRight(ball_position, left_position, right_position, n, m, i);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int position = left_position[i]; position != right_position[i]; position = ModularIncrement(n, position)) {
			ans += Distance(n, ball_position[i], position);
		}
		ans += Distance(n, ball_position[i], right_position[i]);
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}