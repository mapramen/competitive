#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct Node {
	ll val;
	int id;
	int l, r;
	bool operator>(const Node& other) const {
		return val > other.val;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<ll> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	sort(x.begin(), x.end());

	int m = n - 1;
	vector<ll> d(m + 2);
	vector<int> L(m + 2), R(m + 2);
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	vector<bool> vis(m + 2, false);

	// Sentinel nodes to handle boundaries
	d[0] = d[m + 1] = INF;
	for (int i = 1; i <= m; i++) {
		d[i] = x[i] - x[i - 1];
		L[i] = i - 1;
		R[i] = i + 1;
		pq.push({d[i], i, L[i], R[i]});
	}
	L[m + 1] = m;
	R[0] = 1;

	ll current_cost = 0;
	for (int k = 1; k <= n / 2; k++) {
		while (vis[pq.top().id]) pq.pop();

		Node top = pq.top();
		pq.pop();

		current_cost += top.val;
		cout << current_cost << (k == n / 2 ? "" : " ");

		// Regret logic: Replace neighbors with the regret value
		int i = top.id;
		int l = L[i], r = R[i];

		vis[l] = vis[r] = true;
		d[i] = d[l] + d[r] - d[i];

		// Update Linked List
		L[i] = L[l];
		R[i] = R[r];
		R[L[i]] = i;
		L[R[i]] = i;

		pq.push({d[i], i, L[i], R[i]});
	}
	cout << endl;

	return 0;
}