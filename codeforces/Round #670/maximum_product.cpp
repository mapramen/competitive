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
#define M 5

int a[N];

ll Solve(){
  int n;
  
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);

  ll ans = LLONG_MIN;
  for(int x = 0, y = M; x < M; x += 2, y -= 2){
    ll ansx = 1;
    
    for(int i = 1; i <= x; ++i){
      ansx *= a[i];
    }

    for(int i = n; i > n - y; --i){
      ansx *= a[i];
    }

    ans = max(ans, ansx);
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