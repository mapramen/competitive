#include <bits/stdc++.h>

using namespace std;

#define B 30

int GenerateNext(const int a, const int b, const int c, const int x) {
	return (1ll * a * x + b) % c;
}

struct AggStack {
	// Each element is stored as (value, current_agg)
	stack<pair<int, int>> st;

	// Push a new number; compute the new agg
	void push(int x) {
		int cur = st.empty() ? x : st.top().second | x;
		st.push({x, cur});
	}

	// Pop the top element.
	void pop() {
		st.pop();
	}

	// Return the current agg.
	int agg() const {
		return st.top().second;
	}
};

struct AggQueue {
	AggStack in, out;

	// Push a new number into the queue.
	void push(int x) {
		in.push(x);
	}

	// Pop the oldest number.
	void pop() {
		if (out.st.empty()) {
			while (!in.st.empty()) {
				int v = in.st.top().first;
				in.pop();
				out.push(v);
			}
		}
		out.pop();
	}

	// Query
	int query() const {
		if (in.st.empty()) return out.agg();
		if (out.st.empty()) return in.agg();
		return in.agg() | out.agg();
	}
};

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	int x, a, b, c;
	scanf("%d%d%d%d", &x, &a, &b, &c);

	AggQueue Q;
	Q.push(x);

	int ans = k == 1 ? x : 0;

	for (int i = 1; i < n; ++i) {
		x = GenerateNext(a, b, c, x);
		Q.push(x);

		if (i < k - 1) {
			continue;
		}

		if (i >= k) {
			Q.pop();
		}

		ans ^= Q.query();
	}

	printf("%d\n", ans);

	return 0;
}