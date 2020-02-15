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

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 100001

int a[N];
ll p[N];

ll Solve(){
  int n, k;
  
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    p[i] = a[i] + p[i - 1];
    ans += (a[i] % k);
  }

  ll x = (k - (a[n] % k)) % k;
  for(int i = n - 1; i > 0 && p[i] >= x; --i){
    ans = min(ans, (p[i] - x) % k);
    x += ((k - (a[i] % k)) % k);
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