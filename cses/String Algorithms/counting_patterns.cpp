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

char s[5 * N];

string ReadString() {
  scanf("%s", s);
  return string(s);
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

  int q;
  scanf("%d", &q);

  while (q--) {
    string t = ReadString();

    int cur = 0;
    for (char c : t) {
      if (!st[cur].next.count(c)) {
        cur = 0;
        break;
      }
      cur = st[cur].next[c];
    }

    printf("%d\n", st[cur].cnt);
  }

  return 0;
}