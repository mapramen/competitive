#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * To reconstruct the string, we use the property:
 * Suffix(SA[i]) < Suffix(SA[i+1])
 * This is true if:
 * 1. S[SA[i]] < S[SA[i+1]]
 * OR
 * 2. S[SA[i]] == S[SA[i+1]] AND Suffix(SA[i] + 1) < Suffix(SA[i+1] + 1)
 */

int main() {
	// Optimize I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	if (!(cin >> n)) return 0;

	vector<int> sa(n);
	// rank[i] stores the lexicographical rank of the suffix starting at index i
	// We use n + 2 to safely handle (i + 1) lookups and the empty suffix
	vector<int> rank(n + 2, 0);

	for (int i = 0; i < n; ++i) {
		cin >> sa[i];
		// Suffix array values are 1-based in the problem description
		rank[sa[i]] = i + 1;
	}

	// rank[n + 1] remains 0, representing the empty suffix (lexicographically smallest)
	rank[n + 1] = 0;

	string result(n + 1, ' ');
	char current_char = 'a';

	// The first suffix in the suffix array gets the smallest possible character
	result[sa[0]] = current_char;

	for (int i = 0; i < n - 1; ++i) {
		int curr_idx = sa[i];
		int next_idx = sa[i + 1];

		// Check if the suffix starting at (curr_idx + 1) is greater than
		// the suffix starting at (next_idx + 1).
		// If it is, we MUST increment the character at next_idx to ensure
		// Suffix(curr_idx) < Suffix(next_idx).
		if (rank[curr_idx + 1] > rank[next_idx + 1]) {
			current_char++;
		}

		// If we run out of lowercase English letters, no valid string exists
		if (current_char > 'z') {
			cout << -1 << endl;
			return 0;
		}

		result[next_idx] = current_char;
	}

	// Print the reconstructed string (skipping index 0 due to 1-based input)
	for (int i = 1; i <= n; ++i) {
		cout << result[i];
	}
	cout << endl;

	return 0;
}