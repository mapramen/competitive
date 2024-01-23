#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 10001

struct state {
  int len, link;
  map<char, int> next;
};

state st[N * 2];
int sz, last;

void sa_init() {
  for (int i = 0; i <= sz; ++i) {
    st[i].len = 0, st[i].link = 0;
    st[i].next.clear();
  }
  sz = 0;

  st[0].len = 0;
  st[0].link = -1;
  sz++;
  last = 0;
}

void sa_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p = last;
  while (p != -1 && !st[p].next.count(c)) {
    st[p].next[c] = cur;
    p = st[p].link;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      while (p != -1 && st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}

int Solve() {
  int m;
  scanf("%d", &m);

  vector<string> S(m);
  for (string& s : S) {
    cin >> s;
  }
  sort(S.begin(), S.end(), [](auto& a, auto& b) { return a.size() < b.size(); });

  sa_init();
  for (char c : S[0]) {
    sa_extend(c);
  }

  vector<vector<int>> V(S[0].size() + 1);

  vector<int> a(sz), b(sz);
  vector<map<int, vector<int>>> M(sz);

  for (int i = 0; i < sz; ++i) {
    a[i] = st[i].len;
    V[st[i].len].push_back(i);
  }

  for (int k = 0; k < m; ++k) {
    for (int i = 0; i < sz; ++i) {
      b[i] = 0;
      M[i].clear();
    }

    int i = 0, len = 0;
    for (int idx = 0; idx < S[k].size(); ++idx) {
      char c = S[k][idx];
      while (i != 0 && st[i].next.count(c) == 0) {
        i = st[i].link;
        len = st[i].len;
      }

      if (st[i].next.count(c) != 0) {
        i = st[i].next[c];
        ++len;
      }

      M[i][len].push_back(idx);
    }

    for (len = V.size() - 1; len > 0; --len) {
      for (int i : V[len]) {
        int j = st[i].link;
        int jlen = st[j].len;
        for (auto [l, v] : M[i]) {
          sort(v.begin(), v.end());
          if (v.front() + l <= v.back()) {
            b[i] = max(b[i], l);
          }
          M[j][jlen].push_back(v.front());
          M[j][jlen].push_back(v.back());
        }
      }
    }

    for (int i = 0; i < sz; ++i) {
      a[i] = min(a[i], b[i]);
    }
  }

  return *max_element(a.begin(), a.end());
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}