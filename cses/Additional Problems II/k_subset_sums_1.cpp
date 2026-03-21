#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Problem: Find k smallest subset sums.
 * Approach:
 * 1. Calculate the minimum possible sum (sum of all negative numbers).
 * 2. Use absolute values of the array and sort them.
 * 3. Use a Min-Heap to greedily find the next smallest increases from min_sum.
 */

typedef long long ll;

struct State {
	ll sum;
	int idx;

	// We want a min-heap, so we define '>' for the priority queue
	bool operator>(const State& other) const {
		return sum > other.sum;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<ll> abs_v;
	ll min_sum = 0;

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x < 0) {
			min_sum += x;
			abs_v.push_back(-x);
		} else {
			abs_v.push_back(x);
		}
	}

	sort(abs_v.begin(), abs_v.end());

	// The smallest sum is the sum of all negative numbers (or 0 if all are positive)
	vector<ll> results;
	results.push_back(min_sum);

	// Min-heap to explore the smallest increases
	priority_queue<State, vector<State>, greater<State>> pq;

	// Start by considering the smallest non-zero absolute value
	if (n > 0) {
		pq.push({abs_v[0], 0});
	}

	while (results.size() < k && !pq.empty()) {
		State current = pq.top();
		pq.pop();

		results.push_back(current.sum + min_sum);

		if (current.idx + 1 < n) {
			// Branch 1: Include the next element in the subset
			pq.push({current.sum + abs_v[current.idx + 1], current.idx + 1});

			// Branch 2: Replace the current element with the next one
			// This ensures we explore subsets without skipping logic
			pq.push({current.sum - abs_v[current.idx] + abs_v[current.idx + 1], current.idx + 1});
		}
	}

	for (int i = 0; i < k; i++) {
		cout << results[i] << (i == k - 1 ? "" : " ");
	}
	cout << endl;

	return 0;
}