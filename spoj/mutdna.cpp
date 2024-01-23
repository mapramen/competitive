#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

char s[N];

int Solve() {
  int n;
  scanf("%d", &n);

  scanf("%s", s);

  int aa = 0, ab = n, ba = n, bb = 0;
  for (int i = 0; i < n; ++i) {
    char c = s[i];

    int naa = min(aa, ab + 1) + (c != 'A');
    int nab = min(ab, aa + 1) + (c != 'B');
    int nba = min(ba, bb + 1) + (c != 'A');
    int nbb = min(bb, ba + 1) + (c != 'B');

    aa = naa, ab = nab, ba = nba, bb = nbb;
  }

  return min(min(aa, ba), 1 + min(ab, bb));
}

int main() {
  int t = 1;
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}