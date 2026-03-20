#include <bits/stdc++.h>

using namespace std;

#define N 3001

char S[N][N];
int a[N];

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

	bool empty() const {
		return size() == 0;
	}

	size_t size() const {
		return in.st.size() + out.st.size();
	}

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

	void clear() {
		while (!empty()) {
			pop();
		}
	}
};

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; ++i) {
		scanf("%s", S[i]);
	}

	long long ans = 0;
	AggQueue Q;

	for (int x1 = 1; x1 <= n; ++x1) {
		fill(a + 1, a + n + 1, 0);
		for (int x2 = x1; x2 <= n; ++x2) {
			for (int y = 1; y <= n; ++y) {
				a[y] = a[y] | (1 << (S[x2 - 1][y - 1] - 'A'));
				Q.push(a[y]);

				while (!Q.empty() && __builtin_popcount(Q.query()) == k) {
					Q.pop();
				}

				ans += y - Q.size();
			}
			Q.clear();
		}
	}

	printf("%lld\n", ans);

	return 0;
}