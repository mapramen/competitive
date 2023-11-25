#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  if (n == 0 && m == 0) {
    exit(0);
  }

  set<int> S;
  vector<int> a;
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
    for (int y : a) {
      S.insert(abs(x - y));
    }
  }

  return S.size() > n;
}

int main() {
  while (true) {
    printf("%s\n", Solve() ? "Y" : "N");
  }
  return 0;
}