#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

char Solve() {
  int n;
  string s;
  cin >> n >> s;
  return s.back();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%c\n", Solve());
  }
  return 0;
}