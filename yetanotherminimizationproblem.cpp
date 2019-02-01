#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define K 21
#define N 100001

int a[N], c[N], lp, rp;
ll dp[N], inf = 1E18, cost = 0;

void Initialise(int n){
  for(int i = 1; i <= n; ++i)
    c[i] = 0;
  cost = 0;
  lp = 1;
  rp = 0;
}

void Update(int l, int r){
  if(lp != l){
    if(lp < l){
      for( ; lp < l; ++lp){
        int k = a[lp];
        --c[k];
        cost -= c[k];
      }
    }
    else{
      --lp;
      for( ; lp >= l; --lp){
        int k = a[lp];
        cost += c[k];
        ++c[k];
      }
      ++lp;
    }
  }

  if(rp != r){
    if(rp < r){
      ++rp;
      for( ; rp <= r; ++rp){
        int k = a[rp];
        cost += c[k];
        ++c[k];
      }
      --rp;
    }
    else{
      for( ; rp > r; --rp){
        int k = a[rp];
        --c[k];
        cost -= c[k];
      }
    }
  }
}

void DivideAndConquerDP(int k, int l, int r, int lo, int hi){
  if(l > r || lo > hi)
    return ;

  if(lo == hi){
    for(int i = r; i >= l; --i){
      Update(lo, i);
      dp[i] = cost + dp[lo - 1];
    }
  }
  else{
    int m = (l + r) / 2, mid;
    ll ans = inf;

    for(int i = lo; i <= min(m, hi); ++i){
      Update(i, m);
      ll ansx = cost + dp[i - 1];
      if(ansx < ans){
        ans = ansx;
        mid = i;
      }
    }

    DivideAndConquerDP(k, m + 1, r, mid, hi);
    DivideAndConquerDP(k, l, m - 1, lo, mid);

    dp[m] = ans;
  }
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i)
    dp[i] = inf;

  for(int x = 1; x <= k; ++x){
    Initialise(n);
    DivideAndConquerDP(x, 1, n, 1, n);
  }

  printf("%lld\n", dp[n]);

  return 0;
}
