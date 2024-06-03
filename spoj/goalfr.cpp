#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const long double PI = 4 * atan(1.0);

bool IsInside(long double r, long double x, long double y) {
	return x * x + y * y <= r * r;
}

vector<pair<long double, long double>> GetAngles(long double angle1, long double angle2) {
	while (angle1 < 0) {
		angle1 += 2 * PI, angle2 += 2 * PI;
	}

	return angle2 < 2 * PI
						 ? vector<pair<long double, long double>>{{angle1, angle2}}
						 : vector<pair<long double, long double>>{{angle1, 2 * PI}, {0, angle2 - 2 * PI}};
}

vector<pair<long double, long double>> GetGoalAngles(long double x, long double y) {
	long double angle1 = atan2(-3.66 - y, 52.5 - x);
	long double angle2 = atan2(3.66 - y, 52.5 - x);
	return GetAngles(angle1, angle2);
}

vector<pair<long double, long double>> GetGoalKeeperAngles(long double x1, long double y1, long double x2, long double y2, long double r) {
	long double angle = atan2(y2 - y1, x2 - x1);
	long double dangle = asin(r / sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));

	long double angle1 = angle - dangle;
	long double angle2 = angle + dangle;

	return GetAngles(angle1, angle2);
}

bool IsInside(pair<long double, long double> angle1, pair<long double, long double> angle2) {
	return angle1.first <= angle2.first && angle2.second <= angle1.second;
}

bool Solve() {
	long double x1, y1, x2, y2, r;
	scanf("%Lf%LF", &x1, &y1);
	scanf("%Lf%LF%Lf", &x2, &y2, &r);

	if (IsInside(r, x1 - x2, y1 - y2)) {
		return false;
	}

	vector<pair<long double, long double>> goal_angles = GetGoalAngles(x1, y1);
	vector<pair<long double, long double>> goal_keeper_angles = GetGoalKeeperAngles(x1, y1, x2, y2, r);

	for (auto goal_angle : goal_angles) {
		bool is_inside = false;
		for (auto goal_keeper_angle : goal_keeper_angles) {
			if (IsInside(goal_keeper_angle, goal_angle)) {
				is_inside = true;
				break;
			}
		}

		if (!is_inside) {
			return true;
		}
	}

	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%s\n", Solve() ? "Goal!" : "No goal...");
	}
	return 0;
}