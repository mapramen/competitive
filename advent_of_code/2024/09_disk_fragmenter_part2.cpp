#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 10

int main() {
	string s;
	cin >> s;

	vector<int> file_block_start_index, file_block_size;
	vector<priority_queue<int, vector<int>, greater<int>>> free_block_start_indices(B);

	for (int i = 0, k = 0; i < s.size(); ++i) {
		int sz = s[i] - '0';
		if (i % 2 == 0) {
			file_block_start_index.push_back(k);
			file_block_size.push_back(sz);
		} else {
			free_block_start_indices[sz].push(k);
		}
		k += sz;
	}

	for (int d = 0; d < B; ++d) {
		free_block_start_indices[d].push(INT_MAX);
	}

	for (int i = file_block_start_index.size() - 1; i > -1; --i) {
		int d = min_element(free_block_start_indices.begin() + file_block_size[i], free_block_start_indices.end(), [](const auto& a, const auto& b) {
							return a.top() < b.top();
						}) -
						free_block_start_indices.begin();

		const int free_block_index = free_block_start_indices[d].top();

		if (file_block_start_index[i] < free_block_index) {
			continue;
		}

		free_block_start_indices[d].pop();

		file_block_start_index[i] = free_block_index;
		if (d != file_block_size[i]) {
			free_block_start_indices[d - file_block_size[i]].push(free_block_index + file_block_size[i]);
		}
	}

	ll ans = 0;
	for (int i = 0; i < file_block_start_index.size(); ++i) {
		for (int d = file_block_size[i] - 1; d > -1; --d) {
			ans += 1ll * i * (file_block_start_index[i] + d);
		}
	}
	cout << ans << endl;

	return 0;
}