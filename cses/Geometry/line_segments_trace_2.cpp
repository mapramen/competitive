#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef ll ftype;
typedef complex<ftype> point;
#define x real
#define y imag
#define N 100001

ftype dot(point a, point b) {
	return (conj(a) * b).x();
}

ftype F(point a, ftype x) {
	return dot(a, {x, 1});
}

point line[4 * N];

void add_line(point nw, const int v, const int l, const int r, const int ql, const int qr) {
	if (qr < l + 1 || r <= ql) {
		return;
	}

	int m = (l + r) / 2;

	if (ql <= l && r <= qr) {
		bool lef = F(nw, l) > F(line[v], l);
		bool mid = F(nw, m) > F(line[v], m);
		if (mid) {
			swap(line[v], nw);
		}
		if (r - l == 1) {
			return;
		} else if (lef != mid) {
			add_line(nw, 2 * v, l, m, ql, qr);
		} else {
			add_line(nw, 2 * v + 1, m, r, ql, qr);
		}
		return;
	}

	add_line(nw, 2 * v, l, m, ql, qr);
	add_line(nw, 2 * v + 1, m, r, ql, qr);
}

ftype get(int x, int v = 1, int l = 0, int r = N) {
	int m = (l + r) / 2;
	if (r - l == 1) {
		return F(line[v], x);
	} else if (x < m) {
		return max(F(line[v], x), get(x, 2 * v, l, m));
	} else {
		return max(F(line[v], x), get(x, 2 * v + 1, m, r));
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int v = 0; v < 4 * N; ++v) {
		line[v] = {0, LLONG_MIN};
	}

	while (n--) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		const long long m = (y2 - y1) / (x2 - x1);
		const long long c = y1 - m * x1;

		add_line({m, c}, 1, 0, N, x1, x2 + 1);
	}

	for (int x = 0; x <= m; ++x) {
		const auto ans = get(x, 1, 0, N);
		printf("%lld ", ans == LLONG_MIN ? -1 : ans);
	}
	printf("\n");

	return 0;
}