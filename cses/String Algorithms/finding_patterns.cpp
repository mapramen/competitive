#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 500001
#define B 26

char s[N];
bool visited[N], qans[N];

//----------------- Aho-Corasick Automation Start -----------------//
int T[B][N], pi[N], nxt;
bool marked[N];
vector<vector<int>> string_indexes(N);

void Reset() {
  for (int k = 0; k < B; ++k) {
    for (int i = 0; i < N; ++i) {
      T[k][i] = 0;
    }
  }

  for (int i = 0; i < N; ++i) {
    pi[i] = 0, marked[i] = false;
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
  string_indexes[i].push_back(string_index);
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

void DFS(int i) {
  if (visited[i]) {
    return;
  }
  visited[i] = true;
  DFS(pi[i]);
}

int main() {
  string s = ReadString();

  int n;
  scanf("%d", &n);

  Reset();

  for (int i = 1; i <= n; ++i) {
    string t = ReadString();
    AddString(t, i);
  }

  BuildAutomation();

  for (int i = 0, v = 0; i < s.size(); ++i) {
    int k = s[i] - 'a';
    v = T[k][v];
    marked[v] = true;
  }

  for (int v = 1; v <= nxt; ++v) {
    if (marked[v]) {
      DFS(v);
    }
  }

  for (int v = nxt; v > 0; --v) {
    if (!visited[v]) {
      continue;
    }
    for (int string_index : string_indexes[v]) {
      qans[string_index] = true;
    }
  }

  for (int i = 1; i <= n; ++i) {
    printf("%s\n", qans[i] ? "YES" : "NO");
  }

  return 0;
}