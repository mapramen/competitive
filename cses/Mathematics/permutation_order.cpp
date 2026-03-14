#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define N 21

template <typename T>
using ordered_set = tree<
		T,
		null_type,
		less<T>,
		rb_tree_tag,
		// This policy updates nodes' metadata for order statistics.
		tree_order_statistics_node_update>;

long long fact[N];

void Initialize() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = i * fact[i - 1];
	}
}

vector<int> GetPermutation(const int n, long long k) {
	ordered_set<int> S;
	for (int i = 1; i <= n; ++i) {
		S.insert(i);
	}

	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		const int r = k / fact[n - i];
		const int x = *S.find_by_order(r);

		ans.push_back(x);

		S.erase(x);
		k %= fact[n - i];
	}
	return ans;
}

long long GetPermutationRank(const int n, const vector<int>& a) {
	ordered_set<int> S;
	for (int i = 1; i <= n; ++i) {
		S.insert(i);
	}

	long long k = 0;
	for (int i = 1; i <= n; ++i) {
		const int r = S.order_of_key(a[i - 1]);
		S.erase(a[i - 1]);
		k += r * fact[n - i];
	}
	return k;
}

int main() {
	Initialize();

	int t;
	scanf("%d", &t);

	while (t--) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int n;
			long long k;
			scanf("%d%lld", &n, &k);

			for (const int x : GetPermutation(n, k - 1)) {
				printf("%d ", x);
			}
			printf("\n");
		} else {
			int n;
			scanf("%d", &n);

			vector<int> a(n);
			for (int& x : a) {
				scanf("%d", &x);
			}

			printf("%lld\n", 1 + GetPermutationRank(n, a));
		}
	}

	return 0;
}