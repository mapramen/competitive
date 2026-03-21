#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef ll ftype;
typedef complex<ftype> point;
#define x real
#define y imag
#define N 200001

ftype dot(point a, point b) {
	return (conj(a) * b).x();
}

ftype F(point a, ftype x) {
	return dot(a, {x, 1});
}

point line[4 * N];

// r and qr are exclusive (open intervals)
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
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	vector<int> S;
	vector<int> L(n);
	for (int i = 0; i < n; ++i) {
		while (!S.empty() && a[S.back()] >= a[i]) {
			S.pop_back();
		}
		L[i] = S.empty() ? 0 : S.back() + 1;
		S.push_back(i);
	}

	S.clear();
	vector<int> R(n);
	for (int i = n - 1; i >= 0; --i) {
		while (!S.empty() && a[S.back()] >= a[i]) {
			S.pop_back();
		}
		R[i] = S.empty() ? n - 1 : S.back() - 1;
		S.push_back(i);
	}

	for (int v = 0; v < 4 * N; ++v) {
		line[v] = {0, LLONG_MIN};
	}

	for (int i = 0; i < n; ++i) {
		const int l = L[i], r = R[i];

		if (l + k - 1 <= r) {
			add_line({a[i], 1ll * (1 - l) * a[i]}, 1, 0, N, 0, l + k);
			add_line({0, 1ll * k * a[i]}, 1, 0, N, l + k - 1, r + 1);
			add_line({-a[i], 1ll * (r + k) * a[i]}, 1, 0, N, r + 1, n);
		} else {
			add_line({a[i], 1ll * (1 - l) * a[i]}, 1, 0, N, 0, r + 1);
			add_line({0, 1ll * (r - l + 1) * a[i]}, 1, 0, N, r, l + k);
			add_line({-a[i], 1ll * (r + k) * a[i]}, 1, 0, N, l + k - 1, n);
		}
	}

	for (int i = k - 1; i < n; ++i) {
		printf("%lld ", get(i));
	}
	printf("\n");

	return 0;
}