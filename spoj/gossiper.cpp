#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 2101

bitset<N> gossips[N];

void Reset(int n) {
  for (int i = 1; i <= n; ++i) {
    gossips[i].reset();
    gossips[i].set(i);
  }
}

bool Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  if (n == 0 && m == 0) {
    exit(0);
  }

  Reset(n);

  map<string, int> gossiper_to_index;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    gossiper_to_index[s] = i;
  }

  while (m--) {
    string a, b;
    cin >> a >> b;

    int i = gossiper_to_index[a], j = gossiper_to_index[b];
    gossips[i] |= gossips[j];
    gossips[j] |= gossips[i];
  }

  for (int i = 1; i <= n; ++i) {
    if (gossips[i].count() != n) {
      return false;
    }
  }

  return true;
}

int main() {
  while (true) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}