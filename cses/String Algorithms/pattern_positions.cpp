#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 500001
#define B 26

char s[N];
vector<vector<int>> adj(N);
int min_index[N], qans[N];
bool visited[N];

//----------------- Aho-Corasick Automation Start -----------------//
int T[B][N], pi[N], nxt;
vector<vector<pair<int, int>>> string_indexes(N);

void Reset() {
  for (int k = 0; k < B; ++k) {
    for (int i = 0; i < N; ++i) {
      T[k][i] = 0;
    }
  }

  for (int i = 0; i < N; ++i) {
    pi[i] = 0, min_index[i] = INT_MAX;
  }

  nxt = 0;
}

void AddString(string& s, int string_index) {
  int i = 0;
  for (char c : s) {
    int k = c - 'a';
    if (T[k][i] == 0) {
      T[k][i] = ++nxt;
    }
    i = T[k][i];
  }
  string_indexes[i].push_back({string_index, s.size()});
}

void BuildAutomation() {
  queue<int> Q;

  Q.push(0);

  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();

    int pv = pi[v];

    for (int k = 0; k < B; ++k) {
      int u = T[k][v];
      if (u != 0) {
        if (v != 0) {
          pi[u] = T[k][pv];
        }
        Q.push(u);
      } else {
        T[k][v] = T[k][pv];
      }
    }
  }
}
//------------------ Aho-Corasick Automation End ------------------//

string ReadString() {
  scanf("%s", s);
  return string(s);
}

int DFS(int i) {
  if (visited[i]) {
    return min_index[i];
  }

  visited[i] = true;
  for (int j : adj[i]) {
    min_index[i] = min(min_index[i], DFS(j));
  }

  return min_index[i];
}

int main() {
  string s = ReadString();

  int n;
  scanf("%d", &n);

  Reset();

  for (int i = 1; i <= n; ++i) {
    string t = ReadString();
    AddString(t, i);
    qans[i] = -1;
  }

  BuildAutomation();

  for (int i = 0, v = 0; i < s.size(); ++i) {
    int k = s[i] - 'a';
    v = T[k][v];
    min_index[v] = min(min_index[v], i + 1);
  }

  for (int v = 1; v <= nxt; ++v) {
    adj[pi[v]].push_back(v);
  }

  DFS(0);

  for (int v = nxt; v > 0; --v) {
    if (min_index[v] == INT_MAX) {
      continue;
    }

    for (auto [string_index, pattern_length] : string_indexes[v]) {
      qans[string_index] = min_index[v] - pattern_length + 1;
    }
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d\n", qans[i]);
  }

  return 0;
}