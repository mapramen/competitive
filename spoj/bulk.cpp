#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

struct point3d {
	ll x, y, z;

	point3d(ll x, ll y, ll z) : x(x), y(y), z(z) {}

	point3d operator+(const point3d &p) const {
		return point3d(x + p.x, y + p.y, z + p.z);
	}

	point3d operator-(const point3d &p) const {
		return point3d(x - p.x, y - p.y, z - p.z);
	}

	point3d cross(const point3d &p) const {
		return point3d(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
	}

	ll dot(const point3d &p) const {
		return x * p.x + y * p.y + z * p.z;
	}
};

struct point2d {
	ll x, y;

	point2d(const point3d &p) : x(p.x), y(p.y) {}

	point2d(ll x, ll y) : x(x), y(y) {}

	point2d operator+(const point2d &p) const {
		return point2d(x + p.x, y + p.y);
	}

	point2d operator-(const point2d &p) const {
		return point2d(x - p.x, y - p.y);
	}

	ll cross(const point2d &p) const {
		return x * p.y - y * p.x;
	}

	ll dot(const point2d &p) const {
		return x * p.x + y * p.y;
	}
};

point3d
ReadPoint() {
	ll x, y, z;
	scanf("%lld%lld%lld", &x, &y, &z);
	return point3d(x, y, z);
}

vector<point3d> ReadFace() {
	int n;
	scanf("%d", &n);

	vector<point3d> face;
	while (n--) {
		face.push_back(ReadPoint());
	}
	return face;
}

vector<point3d> RemoveRedundantPoints(vector<point3d> face) {
	while (true) {
		bool removed = false;
		for (int i = 0; i < face.size(); ++i) {
			int j = (i + 1) % face.size();
			int k = (i + 2) % face.size();
			if ((face[i].x == face[j].x && face[j].x == face[k].x) || (face[i].y == face[j].y && face[j].y == face[k].y)) {
				face.erase(face.begin() + j);
				removed = true;
			}
		}

		if (!removed) {
			break;
		}
	}
	return face;
}

point3d CalculateCandidatePoint(const vector<point3d> &face) {
	point3d p = face.front();
	for (auto &q : face) {
		if (q.y < p.y || (q.y == p.y && q.x < p.x)) {
			p = q;
		}
	}
	return p;
}

bool IsJustBelowFace(point3d p, const vector<point3d> &face) {
	if (p.z == face.front().z) {
		return false;
	}

	p = point3d(2 * p.x + 1, 2 * p.y + 1, 0);

	int cnt = 0;
	for (int i = 0; i < face.size(); ++i) {
		int j = (i + 1) % face.size();

		point2d a = point2d(2 * face[i].x, 2 * face[i].y);
		point2d b = point2d(2 * face[j].x, 2 * face[j].y);

		if (a.y != b.y || a.y < p.y) {
			continue;
		}

		cnt += (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x));
	}

	return cnt % 2 == 1;
}

ll CalculateFaceArea(const vector<point3d> &face) {
	ll area = 0;
	for (int i = 0; i < face.size(); ++i) {
		int j = (i + 1) % face.size();
		area += point2d(face[i]).cross(point2d(face[j]));
	}
	return abs(area) / 2;
}

ll Solve() {
	int n;
	scanf("%d", &n);

	vector<vector<point3d>> faces;
	while (n--) {
		vector<point3d> face = ReadFace();
		if (face.front().z != face.back().z) {
			continue;
		}
		faces.push_back(RemoveRedundantPoints(face));
	}

	sort(faces.begin(), faces.end(), [](const vector<point3d> &a, const vector<point3d> &b) {
		return a.front().z < b.front().z;
	});

	n = faces.size();
	vector<int> sgn(n);

	for (int i = 0; i < n; ++i) {
		int sign_i = -1;
		point3d p = CalculateCandidatePoint(faces[i]);
		for (int j = i - 1; j >= 0; --j) {
			if (IsJustBelowFace(p, faces[j])) {
				sign_i = -sgn[j];
				break;
			}
		}
		sgn[i] = sign_i;
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll face_area = CalculateFaceArea(faces[i]);
		ans += sgn[i] * CalculateFaceArea(faces[i]) * faces[i].front().z;
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("The bulk is composed of %lld units.\n", Solve());
	}
	return 0;
}