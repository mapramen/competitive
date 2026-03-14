#include <bits/stdc++.h>

using namespace std;

struct line {
	long long a, b;
	double xleft;
	bool type;
	line(long long _a, long long _b) {
		a = _a;
		b = _b;
		type = 0;
	}
	bool operator<(const line& other) const {
		if (other.type) {
			return xleft < other.xleft;
		}
		return a > other.a;
	}
};

double meet(line x, line y) {
	return 1.0 * (y.b - x.b) / (x.a - y.a);
}

struct cht {
	set<line> hull;
	cht() {
		hull.clear();
	}
	typedef set<line>::iterator ite;
	bool hasleft(ite node) {
		return node != hull.begin();
	}
	bool hasright(ite node) {
		return node != prev(hull.end());
	}
	void updateborder(ite node) {
		if (hasright(node)) {
			line temp = *next(node);
			hull.erase(temp);
			temp.xleft = meet(*node, temp);
			hull.insert(temp);
		}
		if (hasleft(node)) {
			line temp = *node;
			temp.xleft = meet(*prev(node), temp);
			hull.erase(node);
			hull.insert(temp);
		} else {
			line temp = *node;
			hull.erase(node);
			temp.xleft = -1e18;
			hull.insert(temp);
		}
	}
	bool useless(line left, line middle, line right) {
		double x = meet(left, right);
		double y = x * middle.a + middle.b;
		double ly = left.a * x + left.b;
		return y > ly;
	}
	bool useless(ite node) {
		if (hasleft(node) && hasright(node)) {
			return useless(*prev(node), *node, *next(node));
		}
		return 0;
	}
	void addline(long long a, long long b) {
		line temp = line(a, b);
		auto it = hull.lower_bound(temp);
		if (it != hull.end() && it->a == a) {
			if (it->b > b) {
				hull.erase(it);
			} else {
				return;
			}
		}
		hull.insert(temp);
		it = hull.find(temp);
		if (useless(it)) {
			hull.erase(it);
			return;
		}
		while (hasleft(it) && useless(prev(it))) {
			hull.erase(prev(it));
		}
		while (hasright(it) && useless(next(it))) {
			hull.erase(next(it));
		}
		updateborder(it);
	}
	long long getbest(long long x) {
		if (hull.empty()) {
			return 1e18;
		}
		line query(0, 0);
		query.xleft = x;
		query.type = 1;
		auto it = hull.lower_bound(query);
		it = prev(it);
		return it->a * x + it->b;
	}
};

int main() {
	int q;
	scanf("%d", &q);

	cht cht;

	while (q--) {
		int t;
		scanf("%d", &t);

		if (t == 1) {
			int a, b;
			scanf("%d%d", &a, &b);
			cht.addline(-a, -b);
		} else {
			int x;
			scanf("%d", &x);
			printf("%lld\n", -cht.getbest(x));
		}
	}

	return 0;
}