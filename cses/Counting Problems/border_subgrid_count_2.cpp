#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<string> grid(n);
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}

	// up[i][j] stores the highest row index such that all cells
	// from that index to i in column j have the same letter.
	vector<vector<int>> up(n, vector<int>(n));
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i) {
			if (i > 0 && grid[i][j] == grid[i - 1][j]) {
				up[i][j] = up[i - 1][j];
			} else {
				up[i][j] = i;
			}
		}
	}

	vector<long long> counts(k, 0);

	for (int r1 = 0; r1 < n; ++r1) {
		for (int r2 = r1; r2 < n; ++r2) {
			for (int c = 0; c < n;) {
				char L = grid[r1][c];

				// If the letters at the top and bottom of this column don't match,
				// this column cannot be part of any rectangle for this row pair.
				if (grid[r2][c] != L) {
					c++;
					continue;
				}

				// Find the maximal horizontal segment where both rows have letter L.
				long long m = 0;
				while (c < n && grid[r1][c] == L && grid[r2][c] == L) {
					// Check if the vertical border at this column is solid L.
					if (up[r2][c] <= r1) {
						m++;
					}
					c++;
				}

				// Any two valid columns in this segment (including a column with itself)
				// form a valid rectangular border.
				if (m > 0) {
					counts[L - 'A'] += (m * (m + 1)) / 2;
				}
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		cout << counts[i] << "\n";
	}

	return 0;
}