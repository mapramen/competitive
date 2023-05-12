#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
  int n;
  scanf("%d", &n);

  bool ans = false;
  while (n--) {
    int x;
    scanf("%d", &x);
    ans = ans || (x % 2 == 1);
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "first" : "second");
  }
  return 0;
}