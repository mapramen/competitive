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

int a[N];

long double ProbabilityOfInversePair(int x, int y) {
  long double ans = x <= y ? x * (x - 1) / 2 : y * (2 * x - y - 1) / 2;
  ans /= (x * y);
  return ans;
}

int main() {
  int n;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  long double ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans += ProbabilityOfInversePair(a[i], a[j]);
    }
  }
  ans = nearbyint(ans * 1000000) / 1000000;

  printf("%Lf\n", ans);

  return 0;
}