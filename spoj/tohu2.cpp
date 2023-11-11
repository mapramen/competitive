#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
  set<char> S;
  for (int i = 1; i < 100; ++i) {
    char c;
    scanf("%d %c", &i, &c);
    if (i % 9 == 0 && i / 9 < 10) {
      S.insert(c);
    }
  }
  return S.size() == 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}