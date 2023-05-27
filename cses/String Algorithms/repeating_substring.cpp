#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

struct state {
  int len, link;
  int cnt = 0;
  ll subtree_cnt = 0;
  map<char, int> next;
};

state st[N * 2];
int sz, last;

void sa_init() {
  st[0].len = 0;
  st[0].link = -1;
  sz++;
  last = 0;
}

void sa_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  st[cur].cnt = 1;
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

char s[N];

string ReadString() {
  scanf("%s", s);
  return s;
}

int main() {
  string s = ReadString();

  sa_init();
  for (char c : s) {
    sa_extend(c);
  }

  int n = s.size();
  vector<vector<int>> V(n + 1);
  for (int i = 0; i <= sz; i++) {
    V[st[i].len].push_back(i);
  }

  for (int len = n; len > 0; --len) {
    for (int i : V[len]) {
      st[st[i].link].cnt += st[i].cnt;
    }
  }
  st[0].cnt = 0;

  vector<pair<int, char>> dp(sz + 1);

  for (int len = n; len > -1; --len) {
    for (int i : V[len]) {
      for (auto [c, j] : st[i].next) {
        if (st[j].cnt >= 2) {
          dp[i] = max(dp[i], {1 + dp[j].first, c});
        }
      }
    }
  }

  string ans;
  for (int cur = 0; dp[cur].first > 0; cur = st[cur].next[dp[cur].second]) {
    ans.push_back(dp[cur].second);
  }

  printf("%s\n", ans.empty() ? "-1" : ans.c_str());

  return 0;
}