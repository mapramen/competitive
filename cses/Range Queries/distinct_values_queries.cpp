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

int a[N], T[N], ans[N];
vector<tiii> queries;

void Update(int i, int x){
  if(i == 0){
    return;
  }

  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int Query(int l, int r){
  return Query(r) - Query(l - 1);
}

int main(){
  int n, q;
  map<int,int> M;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    auto it = M.find(x);
    if(it != M.end()){
      a[i] = it->second;
      it->second = i;
    }
    else{
      M[x] = i;
    }
  }

  for(int x = 1; x <= q; ++x){
    int l, r;
    scanf("%d%d", &l, &r);
    queries.push_back({r, l, x});
  }
  sort(queries.begin(), queries.end());

  int i = 1;
  for(auto query: queries){
    auto [r, l, x] = query;

    for( ; i <= r; ++i){
      Update(a[i], -1);
      Update(i, 1);
    }

    ans[x] = Query(l, r);
  }

  for(int x = 1; x <= q; ++x){
    printf("%d\n", ans[x]);
  }
  
  return 0;
}