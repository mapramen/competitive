#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 3005;
int H[MAXN][MAXN], V[MAXN][MAXN], Up[MAXN][MAXN], Left[MAXN][MAXN];
int tree[26][MAXN];
int n, k;

void update(int l, int i, int delta) {
	for (; i <= n; i += i & -i) tree[l][i] += delta;
}

int query(int l, int i) {
	int sum = 0;
	for (; i > 0; i -= i & -i) sum += tree[l][i];
	return sum;
}

vector<pair<int, int>> removals[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	if (!(cin >> n >> k)) return 0;
	vector<string> grid(n);
	for (int i = 0; i < n; ++i) cin >> grid[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			Up[i][j] = (i > 0 && grid[i][j] == grid[i - 1][j]) ? Up[i - 1][j] + 1 : 1;
			Left[i][j] = (j > 0 && grid[i][j] == grid[i][j - 1]) ? Left[i][j - 1] + 1 : 1;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			V[i][j] = (i + 1 < n && grid[i][j] == grid[i + 1][j]) ? V[i + 1][j] + 1 : 1;
			H[i][j] = (j + 1 < n && grid[i][j] == grid[i][j + 1]) ? H[i][j + 1] + 1 : 1;
		}
	}

	vector<long long> results(k, 0);
	vector<int> temp_c(n), temp_u(n), temp_d(n);

	for (int d = 0; d < 2 * n - 1; ++d) {
		int k_diag = d - (n - 1);
		int r_start = max(0, k_diag);
		int r_end = min(n - 1, n - 1 + k_diag);

		for (int i = r_start; i <= r_end; ++i) {
			int j = i - k_diag;
			temp_c[i] = grid[i][j] - 'A';
			temp_u[i] = min(H[i][j], V[i][j]);
			temp_d[i] = min(Up[i][j], Left[i][j]);
		}

		for (int i = r_start; i <= r_end; ++i) {
			int j = i - k_diag;
			int L = temp_c[i];
			int m_tl = temp_u[i];
			int m_br = temp_d[i];

			update(L, i + 1, 1);
			int rem_idx = i + m_tl - 1;
			if (rem_idx <= r_end) removals[rem_idx].push_back({L, i + 1});

			results[L] += query(L, i + 1) - query(L, i + 1 - m_br);

			for (auto& p : removals[i]) update(p.first, p.second, -1);
			removals[i].clear();
		}
		// Cleanup BIT for the next diagonal
		for (int i = r_start; i <= r_end; ++i) {
			int L = temp_c[i];
			if (i + temp_u[i] - 1 > r_end) update(L, i + 1, -1);
		}
	}

	for (int i = 0; i < k; ++i) cout << results[i] << "\n";
	return 0;
}