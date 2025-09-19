#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n, k, x, d, m;
	scanf("%d%d%d%d%d", &n, &k, &x, &d, &m);

	vector<vector<int>> starts(d + 1), ends(d + 1);
	for (int t = 1; t <= m; ++t) {
		int i, l, r;
		scanf("%d%d%d", &i, &l, &r);
		starts[l].push_back(i);
		ends[r].push_back(i);
	}

	vector<int> lead_freq(n + 1), meeting_freq(m + 1);
	meeting_freq[0] = n;

	int min_k_max_index = 0, min_k_max_index_freq = k;
	int min_k_sum = 0;
	int ans = m;

	for (int t = 1; t <= d; ++t) {
		for (const int i : starts[t - 1]) {
			const int old_freq = lead_freq[i], new_freq = old_freq + 1;

			if (new_freq <= min_k_max_index) {
				++min_k_sum;
				min_k_max_index_freq += (new_freq == min_k_max_index);
			} else if (old_freq == min_k_max_index) {
				if (min_k_max_index_freq == meeting_freq[min_k_max_index]) {
					++min_k_sum;
					++min_k_max_index;
					min_k_max_index_freq = 1;
				}
			}

			++lead_freq[i];
			--meeting_freq[old_freq];
			++meeting_freq[new_freq];
		}

		if (t < x) {
			continue;
		}

		for (const int i : ends[t - x]) {
			const int old_freq = lead_freq[i], new_freq = old_freq - 1;

			if (old_freq < min_k_max_index) {
				--min_k_sum;
			} else if (old_freq == min_k_max_index) {
				--min_k_sum;
				--min_k_max_index_freq;

				if (min_k_max_index_freq == 0) {
					--min_k_max_index;
					min_k_max_index_freq = meeting_freq[new_freq] + 1;
				}
			}

			--lead_freq[i];
			--meeting_freq[old_freq];
			++meeting_freq[new_freq];
		}

		ans = min(ans, min_k_sum);
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}