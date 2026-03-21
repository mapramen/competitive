#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State {
	long long sum;
	int i;			// Active index in the subset (0 to m-1)
	int pos;		// Current position in the sorted array
	int limit;	// Upper bound for this index

	bool operator>(const State& other) const {
		return sum > other.sum;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<long long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	long long current_sum = 0;
	for (int i = 0; i < m; ++i) current_sum += a[i];

	priority_queue<State, vector<State>, greater<State>> pq;
	// Initial state: start by moving the last element (index m-1)
	pq.push({current_sum, m - 1, m - 1, n});

	for (int count = 0; count < k; ++count) {
		State top = pq.top();
		pq.pop();

		cout << top.sum << (count == k - 1 ? "" : " ");

		// Transition 1: Move the current active index further right
		if (top.pos + 1 < top.limit) {
			pq.push({top.sum - a[top.pos] + a[top.pos + 1], top.i, top.pos + 1, top.limit});
		}

		// Transition 2: Start moving the index to the left of the current one
		// Only allowed if the current index has moved at least once (top.pos > top.i)
		if (top.i > 0 && top.pos > top.i) {
			pq.push({top.sum - a[top.i - 1] + a[top.i], top.i - 1, top.i, top.pos});
		}
	}
	cout << endl;

	return 0;
}