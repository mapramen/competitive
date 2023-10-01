#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
  int a, b;
  scanf("%d%d", &a, &b);
  return (a + b) % 2 == 1 || a % 2 == 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "Suresh" : "Ramesh");
  }
  return 0;
}