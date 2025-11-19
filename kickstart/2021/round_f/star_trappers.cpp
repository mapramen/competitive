#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double inf = numeric_limits<double>::max();
const double pi = atan2(0, -1);

struct pt {
	long long x, y;
	pt() {}
	pt(long long _x, long long _y) : x(_x), y(_y) {}
	bool operator==(const pt& p) const { return x == p.x && y == p.y; }
	pt operator+(const pt& p) const { return pt(x + p.x, y + p.y); }
	pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
	long long cross(const pt& p) const { return x * p.y - y * p.x; }
	long long dot(const pt& p) const { return x * p.x + y * p.y; }
	long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
	long long dot(const pt& a, const pt& b) const { return (a - *this).dot(b - *this); }
	long long sqrLen() const { return this->dot(*this); }
};

pt ReadPoint() {
	int x, y;
	cin >> x >> y;
	return pt(x, y);
}

long long CalculateDoubleArea(const pt a, const pt b, const pt c) {
	return abs(a.cross(b, c));
}

bool IsInside(const vector<pt>& pts, const pt ps) {
	const int n = pts.size();

	long long area_sum = 0;
	for (int i = 0; i < n; ++i) {
		const int j = (i + 1) % n;
		const auto area = CalculateDoubleArea(ps, pts[i], pts[j]);

		if (area == 0) {
			return false;
		}

		area_sum += area;
	}

	long long polygon_area = 0;
	for (int i = 0; i < n - 2; ++i) {
		polygon_area += CalculateDoubleArea(pts[n - 1], pts[i], pts[i + 1]);
	}

	return area_sum == polygon_area;
}

double CalculatePerimeter(const vector<pt> pts, const pt ps) {
	if (!IsInside(pts, ps)) {
		return inf;
	}

	const int n = pts.size();

	double ans = 0;
	for (int i = 0; i < n; ++i) {
		const int j = (i + 1) % n;
		ans += sqrt((pts[j] - pts[i]).sqrLen());
	}
	return ans;
}

double CalculateMinTrianglePerimeter(const vector<pt>& pts, const pt ps) {
	const int n = pts.size();

	double ans = inf;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				ans = min(ans, CalculatePerimeter({pts[i], pts[j], pts[k]}, ps));
			}
		}
	}

	return ans;
}

double CalculateMinQuadrilateralPerimeter(const vector<pt>& pts, const pt ps) {
	const int n = pts.size();

	unordered_map<double, pt> angle_to_point;
	for (auto p : pts) {
		if (p == ps) {
			continue;
		}

		const pt v = p - ps;
		double angle = pi + atan2(v.y, v.x);

		if (angle >= 2 * pi) {
			angle -= 2 * pi;
		}

		const auto it = angle_to_point.find(angle);

		if (it == angle_to_point.end()) {
			angle_to_point[angle] = p;
			continue;
		}

		const auto q = it->second;
		if (v.sqrLen() < (q - ps).sqrLen()) {
			it->second = p;
		}
	}

	vector<pair<pt, pt>> diagonals;
	for (const auto [angle1, p1] : angle_to_point) {
		if (angle1 >= pi) {
			continue;
		}

		for (const auto [angle2, p2] : angle_to_point) {
			if (angle2 <= angle1) {
				continue;
			}

			const auto angle_diff = abs(angle2 - angle1 - pi);
			if (angle_diff >= 1E-6) {
				continue;
			}

			diagonals.push_back({p1, p2});
		}
	}

	const int m = diagonals.size();
	double ans = inf;
	for (int i = 0; i < m; ++i) {
		const auto [p1, p3] = diagonals[i];
		for (int j = i + 1; j < m; ++j) {
			const auto [p2, p4] = diagonals[j];
			ans = min(ans, CalculatePerimeter({p1, p2, p3, p4}, ps));
		}
	}
	return ans;
}

double Solve() {
	int n;
	cin >> n;

	vector<pt> pts;
	while (n--) {
		pts.push_back(ReadPoint());
	}

	const pt ps = ReadPoint();

	return min(CalculateMinTrianglePerimeter(pts, ps), CalculateMinQuadrilateralPerimeter(pts, ps));
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		const double ans = Solve();

		printf("Case #%d: ", k);
		if (ans == inf) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%.9lf\n", ans);
		}
	}
	return 0;
}