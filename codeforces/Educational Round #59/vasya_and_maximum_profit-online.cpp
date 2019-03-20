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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tlii tuple< ll, int, int >
#define PB push_back
#define MP make_pair
#define N 300001
#define M (1 << 20)

int c[N], d[N];

//----------------------------------------- Segment Tree -----------------------------------------//
ll lazyVal[M], sum[M], prefixAns[M], suffixAns[M], Ans[M];

void UpdateNode(int k, ll x){
  lazyVal[k] += x;
  prefixAns[k] += x;
  Ans[k] += x;
}

void LazyUpdateChildren(int k){
  if(lazyVal[k] == 0){
    return ;
  }
  UpdateNode(2 * k + 1, lazyVal[k]);
  UpdateNode(2 * k + 2, lazyVal[k]);
  lazyVal[k] = 0;
}

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  
  sum[k] = sum[k1] + sum[k2];
  prefixAns[k] = max(prefixAns[k1], sum[k1] + prefixAns[k2]);
  suffixAns[k] = max(suffixAns[k2], sum[k2] + suffixAns[k1]);
  Ans[k] = max(suffixAns[k1] + prefixAns[k2], max(Ans[k1], Ans[k2]));
}

void Update(int k, int l, int r, int ql, int qr, ll x, bool isValUpdate){
  if(r < ql || qr < l){
    return ;
  }

  if(ql <= l && r <= qr){
    if(isValUpdate){
      UpdateNode(k, x);
    }
    else{
      sum[k] = x;
      prefixAns[k] = x;
      suffixAns[k] = x;
      Ans[k] = x;
    }
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x, isValUpdate);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x, isValUpdate);
  Combine(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n;
  ll a;

  scanf("%d%lld", &n, &a);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &d[i], &c[i]);
  }

  ll ans = 0;
  stack< tlii > S;

  for(int i = n; i > 0; --i){
    Update(0, 1, n, i, i, a - c[i], false);

    ll x = (i == n) ? 0ll : d[i + 1] - d[i];
    x *= x;

    int j = i + 1;
    while(!S.empty()){
      ll y;
      int l, r;
      tie(y, l, r) = S.top();
      
      if(y > x){
        break;
      }

      S.pop();

      Update(0, 1, n, l, r, y - x, true);
      j = r;
    }

    S.push(make_tuple(x, i + 1, j));
    S.push(make_tuple(0ll, i, i));
    ans = max(ans, Ans[0]);
  }

  printf("%lld\n", ans);

  return 0;
}