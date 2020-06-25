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
#define N 200001

int a[N];
ll T[N];

void Update(int i, int x){
  x -= a[i];
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

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Update(i, x);
  }

  while(q--){
    int k, l, r;
    scanf("%d%d%d", &k, &l, &r);

    if(k == 1){
      Update(l, r);
    }
    else{
      printf("%lld\n", Query(l, r));
    }
  }
  
  return 0;
}