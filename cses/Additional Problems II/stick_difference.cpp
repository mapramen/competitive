#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Structure to store element state
struct Element {
	int id;
	int p;
	int a;
	long long val;

	// Custom comparator for max-heap (to simulate priority logic)
	bool operator<(const Element& other) const {
		return val < other.val;
	}
};

int main() {
	// Optimization for fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	if (!(cin >> n)) return 0;
	cin >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 1. Compute U[j] and M[j]
	priority_queue<Element> pqU;
	vector<int> U(m + 1);
	vector<int> M(m + 1);
	int min_val = INT_MAX;

	for (int i = 0; i < n; i++) {
		long long ceil_val = a[i];
		pqU.push({i, 1, a[i], ceil_val});
		min_val = min(min_val, a[i]);
	}

	U[0] = (int)pqU.top().val;
	M[0] = min_val;

	for (int j = 1; j <= m; j++) {
		Element elem = pqU.top();
		pqU.pop();

		elem.p++;
		elem.val = (1LL * elem.a + elem.p - 1) / elem.p;
		pqU.push(elem);

		U[j] = (int)pqU.top().val;
		min_val = min(min_val, elem.a / elem.p);
		M[j] = min_val;
	}

	// 2. Compute L[k] using a max-heap
	priority_queue<Element> pqL;
	vector<int> L(m + 1);
	for (int i = 0; i < n; i++) {
		long long floor_val = a[i] / 2LL;
		pqL.push({i, 2, a[i], floor_val});
	}

	for (int k = 1; k <= m; k++) {
		Element elem = pqL.top();
		pqL.pop();

		L[k] = (int)elem.val;
		elem.p++;
		elem.val = 1LL * elem.a / elem.p;
		pqL.push(elem);
	}

	// 3. Build RMQ (Sparse Table) over D[j] = U[j] - M[j]
	vector<int> D(m + 1);
	for (int j = 0; j <= m; j++) {
		D[j] = U[j] - M[j];
	}

	int maxLog = log2(m + 1) + 1;
	vector<vector<int>> st(maxLog, vector<int>(m + 1));
	for (int j = 0; j <= m; j++) {
		st[0][j] = D[j];
	}

	for (int i = 1; i < maxLog; i++) {
		for (int j = 0; j + (1 << i) <= m + 1; j++) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}

	auto queryRMQ = [&](int L_idx, int R_idx) {
		int k_log = log2(R_idx - L_idx + 1);
		return min(st[k_log][L_idx], st[k_log][R_idx - (1 << k_log) + 1]);
	};

	// 4. Compute Answer for each k
	vector<int> ans(m + 1);
	for (int k = 1; k <= m; k++) {
		int low = 0, high = k, j_star = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (M[mid] >= L[k]) {
				j_star = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}

		int cur_ans = INT_MAX;
		if (j_star != -1) {
			cur_ans = min(cur_ans, U[j_star] - L[k]);
		}
		if (j_star + 1 <= k) {
			cur_ans = min(cur_ans, queryRMQ(j_star + 1, k));
		}
		ans[k] = cur_ans;
	}

	// Output results
	for (int k = 1; k <= m; k++) {
		cout << ans[k] << (k == m ? "" : " ");
	}
	cout << endl;

	return 0;
}