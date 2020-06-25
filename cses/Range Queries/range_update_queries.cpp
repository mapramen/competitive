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
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

void Update(int l, int r, int x){
  Update(l, x);
  Update(r + 1, -x);
}

ll Query(int i){
  ll ans = a[i];
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(q--){
    int k;

    scanf("%d", &k);

    if(k == 1){
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      Update(l, r, x);
    }
    else{
      int i;
      scanf("%d", &i);
      printf("%lld\n", Query(i));
    }
  }
  
  return 0;
}