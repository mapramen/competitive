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
#define N 100001

int w[N], c[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &w[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    ++c[i], ++c[j];
  }
  
  ll ans = 0;
  vector<int> v;
  for(int i = 1; i <= n; ++i){
    int k = c[i], x = w[i];
    ans += w[i];
    while(--k){
      v.push_back(x);
    }
    c[i] = 0;
  }
  sort(v.begin(), v.end());
  v.push_back(0);

  for( ; !v.empty(); v.pop_back()){
    ans += v.back();
    printf("%lld ", ans);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}