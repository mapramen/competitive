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
#define N 3001

vector<ll> dp;
vector<vector<ll>> C;

void PreProcess(){
  for(int k = 0; k < C.size(); ++k){
    vector<ll> &v = C[k];
    for(int i = 1, n = v.size(); i < n; ++i){
      v[i] += v[i - 1];
    }
  }
}

void RelaxKnapsack(int l, int r){
  for(int i = l; i <= r; ++i){
    int w = C[i].size() - 1;
    ll val = C[i].back();

    for(int x = dp.size() - 1, y = x - w; y >= 0; --x, --y){
      dp[x] = max(dp[x], dp[y] + val);
    }
  }
}

ll KnapsackAns(int k){
  vector<ll> &a = C[k];

  int n = dp.size() - 1, m = a.size() - 1;
  ll ans = 0;

  for(int i = 0, j = n; i <= m; ++i, --j){
    ans = max(ans, dp[j] + a[i]);
  }

  return ans;
}

ll DivideAndConquer(int l, int r, int kl, int kr){
  vector<ll> rollBack(dp);
  RelaxKnapsack(kl, kr);

  ll ans = 0;
  if(l == r){
    ans = KnapsackAns(l);
  }
  else{
    int mid = (l + r) / 2;
    ans = max(DivideAndConquer(l, mid, mid + 1, r), DivideAndConquer(mid + 1, r, l, mid));
  }

  swap(dp, rollBack);
  rollBack.clear();
  return ans;
}

int main(){
  int n, m;
  scanf("%d%d", &m, &n);

  dp.resize(n + 1);
  for(int t = 0; t < m; ++t){
    int k;
    vector<ll> a;
    scanf("%d", &k);
    a.resize(k + 1);

    for(int i = 1; i <= k; ++i){
      scanf("%lld", &a[i]);
    }

    if(k > n){
      a.resize(n + 1);
    }

    C.push_back(a);
  }

  PreProcess();

  printf("%lld\n", DivideAndConquer(0, m - 1, INT_MAX, INT_MIN));

  return 0;
}