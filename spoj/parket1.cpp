#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Sqrt(int n) {
  int x = max(0.0, sqrt(n) - 1);
  while (x * x < n) {
    ++x;
  }
  return x;
}

int main() {
  int R, B;
  cin >> R >> B;

  int a = 1, b = -(R + 4) / 2, c = R + B;
  int l = (-b + Sqrt(b * b - 4 * a * c)) / (2 * a);
  int w = (-b - Sqrt(b * b - 4 * a * c)) / (2 * a);

  printf("%d %d\n", l, w);

  return 0;
}