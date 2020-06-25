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
#define tiii tuple<int,int,int>
#define N 200001

vector<vector<int>> adj(N);
int a[N], latestQueryNumber[N];
ll T[N], qAns[N];
vector<tiii> queries(1);

void Update(int i, int x){
  a[i] += x;
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

ll Query(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll Query(int l, int r){
  return Query(r) - Query(l - 1);
}

void DFS(int i){
  auto [k, l, r] = queries[i];

  if(k == 1){
    r -= a[l];
    Update(l, r);
  }

  for(int j: adj[i]){
    DFS(j);
  }

  if(k == 1){
    Update(l, -r);
  }

  if(k == 2){
    qAns[i] = Query(l, r);
  }
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Update(i, x);
  }

  for(int t = 1, c = 1; t <= q; ++t){
    int k, i, l, r;
    scanf("%d%d", &k, &i);

    if(k < 3){
      scanf("%d%d", &l, &r);
    }
    else{
      ++c;
      latestQueryNumber[c] = latestQueryNumber[i];
      i = c;
    }

    queries.push_back({k, l, r});
    adj[latestQueryNumber[i]].push_back(t);
    latestQueryNumber[i] = t;
  }

  DFS(0);

  for(int t = 1; t <= q; ++t){
    auto [k, l, r] = queries[t];
    if(k == 2){
      printf("%lld\n", qAns[t]);
    }
  }
  
  return 0;
}