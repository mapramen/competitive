#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 101
#define PRECISION 0.000001

int a[N];

int NumberOfInversePair(int x, int y) {
  if (x <= y) {
    return x * (x - 1) / 2;
  }

  return y * (x - y) + NumberOfInversePair(y, y);
}

double ProbabilityOfInversePair(int x, int y) {
  return 1.0 * NumberOfInversePair(x, y) / (x * y);
}

int main() {
  int n;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans += ProbabilityOfInversePair(a[i], a[j]);
    }
  }
  ans = round(ans / PRECISION) * PRECISION;

  printf("%lf\n", ans);

  return 0;
}