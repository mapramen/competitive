#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct PairSum {
	ll sum;
	uint32_t mask;
};

struct Entry {
	ll sum;
	uint32_t m1, m2;	// store up to two different masks for this sum
};

static vector<PairSum> build_half(const vector<ll>& a) {
	int k = (int)a.size();
	int N = 1 << k;

	vector<ll> s(N, 0);
	vector<PairSum> res(N);
	res[0] = {0, 0};

	for (int mask = 1; mask < N; ++mask) {
		int b = __builtin_ctz(mask);
		int prev = mask & (mask - 1);
		s[mask] = s[prev] + a[b];
		res[mask] = {s[mask], (uint32_t)mask};
	}

	sort(res.begin(), res.end(), [](const PairSum& x, const PairSum& y) {
		return x.sum < y.sum;
	});
	return res;
}

static ll count_leq(ll m, const vector<ll>& L, const vector<ll>& R) {
	ll cnt = 0;
	int j = (int)R.size() - 1;
	for (int i = 0; i < (int)L.size(); ++i) {
		while (j >= 0 && L[i] + R[j] > m) --j;
		cnt += (j + 1);
	}
	// subtract the empty subset (left empty + right empty)
	return cnt - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> x(n);
	for (int i = 0; i < n; ++i) cin >> x[i];

	int n1 = n / 2;
	int n2 = n - n1;

	vector<ll> left(x.begin(), x.begin() + n1);
	vector<ll> right(x.begin() + n1, x.end());

	// Build all subset sums for both halves.
	auto leftPairs = build_half(left);
	auto rightPairs = build_half(right);

	vector<ll> sumL, sumR;
	sumL.reserve(leftPairs.size());
	sumR.reserve(rightPairs.size());
	for (auto& p : leftPairs) sumL.push_back(p.sum);
	for (auto& p : rightPairs) sumR.push_back(p.sum);

	ll total = 0;
	for (ll v : x) total += v;

	// Binary search the smallest m with count_nonempty_subsets(<=m) > m.
	ll lo = -1, hi = total;
	while (hi - lo > 1) {
		ll mid = lo + (hi - lo) / 2;
		if (count_leq(mid, sumL, sumR) > mid)
			hi = mid;
		else
			lo = mid;
	}
	ll target = hi;

	// Compress left sums: keep up to two different masks for each sum.
	vector<Entry> leftMap;
	for (auto& p : leftPairs) {
		if (leftMap.empty() || leftMap.back().sum != p.sum) {
			leftMap.push_back({p.sum, p.mask, UINT32_MAX});
		} else {
			Entry& e = leftMap.back();
			if (e.m1 != p.mask && e.m2 == UINT32_MAX) e.m2 = p.mask;
		}
	}

	auto findLeft = [&](ll need) -> const Entry* {
		auto it = lower_bound(
				leftMap.begin(), leftMap.end(), need,
				[](const Entry& e, ll val) { return e.sum < val; });
		if (it != leftMap.end() && it->sum == need) return &*it;
		return nullptr;
	};

	// Find two different full subsets with sum = target.
	vector<ull> fullMasks;
	for (const auto& rp : rightPairs) {
		if (rp.sum > target) break;
		ll need = target - rp.sum;
		const Entry* e = findLeft(need);
		if (!e) continue;

		uint32_t cand[2] = {e->m1, e->m2};
		for (uint32_t lm : cand) {
			if (lm == UINT32_MAX) continue;
			ull full = (ull)lm | ((ull)rp.mask << n1);
			if (fullMasks.empty() || fullMasks[0] != full) {
				fullMasks.push_back(full);
				if ((int)fullMasks.size() == 2) break;
			}
		}
		if ((int)fullMasks.size() == 2) break;
	}

	if ((int)fullMasks.size() < 2) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	ull A = fullMasks[0] & ~fullMasks[1];
	ull B = fullMasks[1] & ~fullMasks[0];

	auto print_mask = [&](ull m) {
		vector<ll> vals;
		for (int i = 0; i < n; ++i) {
			if (m & (1ULL << i)) vals.push_back(x[i]);
		}
		cout << vals.size() << '\n';
		for (int i = 0; i < (int)vals.size(); ++i) {
			cout << vals[i] << (i + 1 == (int)vals.size() ? '\n' : ' ');
		}
		if (vals.empty()) cout << '\n';
	};

	print_mask(A);
	print_mask(B);

	return 0;
}