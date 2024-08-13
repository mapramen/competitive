#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

template <class T>
bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0;
}

/**
 * Description: Given J jobs and W workers (J <= W), computes the minimum cost
 * to assign each prefix of jobs to distinct workers.
 *
 * @tparam T a type large enough to represent integers on the order of J *
 * max(|C|)
 * @param C a matrix of dimensions JxW such that C[j][w] = cost to assign j-th
 * job to w-th worker (possibly negative)
 *
 * @return a vector of length J, with the j-th entry equaling the minimum cost
 * to assign the first (j+1) jobs to distinct workers
 * Time: O(J^2W)
 * Source:
 * http://e-maxx.ru/algo/assignment_hungary#6
 * https://en.wikipedia.org/wiki/Hungarian_algorithm
 * Verification:
 * https://www.spoj.com/problems/BABY/
 * https://open.kattis.com/problems/cordonbleu
 * more problems at https://codeforces.com/blog/entry/63701
 */
template <class T>
vector<T> hungarian(const vector<vector<T>>& C) {
	const int J = C.size(), W = C.front().size();
	assert(J <= W);
	/// job[w] = job assigned to w-th worker, or -1 if no job assigned
	/// note: a W-th worker was added for convenience
	vector<int> job(W + 1, -1);
	vector<T> ys(J), yt(W + 1);	 /// potentials
	/// -yt[W] will equal the sum of all deltas
	vector<T> answers;
	const T inf = numeric_limits<T>::max();
	for (int j_cur = 0; j_cur < J; ++j_cur) {	 /// assign j_cur-th job
		int w_cur = W;
		job[w_cur] = j_cur;
		/// min reduced cost over edges from Z to worker w
		vector<T> min_to(W + 1, inf);
		vector<int> prv(W + 1, -1);	 /// previous worker on alternating path
		vector<bool> in_Z(W + 1);		 /// whether worker is in Z
		while (job[w_cur] != -1) {	 /// runs at most j_cur + 1 times
			in_Z[w_cur] = true;
			const int j = job[w_cur];
			T delta = inf;
			int w_next;
			for (int w = 0; w < W; ++w) {
				if (!in_Z[w]) {
					if (ckmin(min_to[w], C[j][w] - ys[j] - yt[w]))
						prv[w] = w_cur;
					if (ckmin(delta, min_to[w])) w_next = w;
				}
			}
			/// delta will always be non-negative,
			/// except possibly during the first time this loop runs
			/// if any entries of C[j_cur] are negative
			for (int w = 0; w <= W; ++w) {
				if (in_Z[w])
					ys[job[w]] += delta, yt[w] -= delta;
				else
					min_to[w] -= delta;
			}
			w_cur = w_next;
		}
		/// update assignments along alternating path
		for (int w; w_cur != -1; w_cur = w) job[w_cur] = job[w = prv[w_cur]];
		answers.push_back(-yt[W]);
	}
	return answers;
}

map<int, int> index_map;
vector<vector<int>> adj;

void Reset(int n) {
	index_map.clear();
	adj.clear();

	adj.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		index_map[i] = i;
	}
}

int GetIndex(int i) {
	if (index_map.count(i) == 0) {
		index_map[i] = index_map.size();
		adj.push_back(vector<int>());
	}
	return index_map[i];
}

vector<int> Distance(int s) {
	queue<int> Q;
	vector<int> d(adj.size(), adj.size());

	Q.push(s);
	d[s] = 0;

	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();

		for (int j : adj[i]) {
			if (d[j] == adj.size()) {
				d[j] = d[i] + 1;
				Q.push(j);
			}
		}
	}

	return d;
}

int Solve() {
	int n;
	scanf("%d", &n);

	Reset(n);

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	int m;
	scanf("%d", &m);

	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);

		i = GetIndex(i), j = GetIndex(j);

		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	vector<vector<int>> C(n, vector<int>(n, 0));
	for (int i = 1; i <= n; ++i) {
		vector<int> d = Distance(GetIndex(a[i]));
		for (int j = 1; j <= n; ++j) {
			C[i - 1][j - 1] = d[j];
		}
	}

	return hungarian(C).back();
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}