#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define K 17

int phi[N];
ll a[N], dp[K][N];

ll C(int l, int r){
  ll ans = 0;
  while(l <= r){
    int k = r / l;
    int x = r / k;
    ans += (x - l + 1) * a[k];
    l = x + 1;
  }
  return ans;
}

void Solve(ll dpPrev[], ll dpCur[], int i, int j, int l, int r){
  if(i > j){
    return;
  }

  int mid = i + (j - i) / 2, o = -1;
  ll ans = LLONG_MAX;

  for(int x = min(mid, r); x >= l; --x){
    ll ansx = dpPrev[x - 1] + C(x, mid) + (mid - x + 1);
    if(ansx < ans){
      ans = ansx, o = x;
    }
  }

  dpCur[mid] = ans;
  Solve(dpPrev, dpCur, i, mid - 1, l, o);
  Solve(dpPrev, dpCur, mid + 1, j, o, r);
}

void Initialise(){
  for(int i = 1; i < N; ++i){
    phi[i] = i;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      phi[j] -= phi[i];
    }
  }

  for(int i = 2; i < N; ++i){
    a[i] = phi[i] + a[i - 1];
  }

  for(int k = 0; k < K; ++k){
    for(int i = 0; i < N; ++i){
      dp[k][i] = 1E15;
    }
  }

  dp[0][0] = 0ll;
  for(int k = 1; k < K; ++k){
    Solve(dp[k - 1], dp[k], 1, N - 1, 1, N - 1);
  }
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);

  while(t--){
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", k < K ? dp[k][n] : 1ll * n);
  }

  return 0;
}