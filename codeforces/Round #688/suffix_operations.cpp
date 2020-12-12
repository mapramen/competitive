#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200002

int a[N];

int GetContribution(int n, int i){
  return (i != 1) * abs(a[i] - a[i - 1]) + (i != n) * abs(a[i] - a[i + 1]);
}

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll s = 0;
  for(int i = 1; i <= n; ++i){
    s += GetContribution(n, i);
  }
  s /= 2;

  ll ans = LLONG_MAX;
  for(int i = 1; i <= n; ++i){
    int p = a[i];
    s -= GetContribution(n, i);

    a[i] = a[i - 1];
    ans = min(ans, s + GetContribution(n, i));

    a[i] = a[i + 1];
    ans = min(ans, s + GetContribution(n, i));

    a[i] = p;
    s += GetContribution(n, i);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}