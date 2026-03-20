#include <bits/stdc++.h>

using namespace std;

namespace IO {
inline int readChar() { return getchar_unlocked(); }

inline int readInt() {
	int c = readChar(), x = 0;
	while (c <= ' ') c = readChar();
	for (; c > ' '; c = readChar()) x = x * 10 + c - '0';
	return x;
}

inline void writeChar(char c) { putchar_unlocked(c); }

inline void writeInt(int x, char end = '\0') {
	if (x == 0) {
		writeChar('0');
	} else {
		char buf[12];
		int len = 0;
		for (; x > 0; x /= 10) buf[len++] = '0' + x % 10;
		for (int i = len - 1; i >= 0; --i) writeChar(buf[i]);
	}
	if (end) writeChar(end);
}

inline void writeStr(const char* s) {
	while (*s) writeChar(*s++);
}
}	 // namespace IO

#define N 400005

vector<vector<int>> adj(N);
int match[N + 1], dis[N + 1];
bool visited[N + 1];
const int inf = 1E9;

void ResetVisited() {
	for (int i = 0; i <= N; ++i) {
		visited[i] = 0;
	}
}

bool BFS(const vector<int>& U) {
	queue<int> Q;

	for (const auto u : U) {
		if (match[u] == N) {
			dis[u] = 0;
			Q.push(u);
		} else {
			dis[u] = inf;
		}
	}

	dis[N] = inf;

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		visited[u] = 1;
		if (dis[u] < dis[N]) {
			for (const auto v : adj[u]) {
				if (dis[match[v]] == inf) {
					visited[v] = 1;
					dis[match[v]] = 1 + dis[u];
					Q.push(match[v]);
				}
			}
		}
	}

	return (dis[N] != inf);
}

bool DFS(const int u) {
	if (u == N) {
		return true;
	}

	for (const auto v : adj[u]) {
		if (dis[match[v]] == 1 + dis[u]) {
			if (DFS(match[v])) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
	}

	dis[u] = inf;
	return false;
}

int HopcroftKarpMaximumMatching(const vector<int>& U, const vector<int>& V) {
	for (const auto u : U) {
		match[u] = N;
	}
	for (const auto v : V) {
		match[v] = N;
	}
	int matching = 0;
	for (ResetVisited(); BFS(U); ResetVisited()) {
		for (const auto u : U) {
			if (match[u] == N) {
				matching += DFS(u);
			}
		}
	}
	return matching;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(n + j);
	}

	vector<int> U(n), V(n);
	iota(U.begin(), U.end(), 1);
	iota(V.begin(), V.end(), n + 1);

	if (HopcroftKarpMaximumMatching(U, V) < n - 2) {
		printf("NO\n");
		return 0;
	}

	printf("YES\n");

	vector<vector<int>> splits;
	for (int j = 1; j <= n; ++j) {
		if (match[n + j] != N) {
			continue;
		}

		vector<int> split{j};
		for (int i = j; match[i] != N;) {
			i = match[i] - n;
			split.push_back(i);
		}
		splits.push_back(split);
	}

	splits.resize(2);

	for (const auto& split : splits) {
		printf("%lu ", split.size());
		for (auto u : split) {
			printf("%d ", u);
		}
		printf("\n");
	}

	return 0;
}