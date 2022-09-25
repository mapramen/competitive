#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100000
#define MOD 1000000007

int a[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a[x] = i;
  }

  int ans = 1;
  for(int x = 1, c = 0, l = a[0], r = a[0]; x < n; ++x){
    int i = a[x];
    int nl = min(l, i), nr = max(r, i);

    if(nl != l || nr != r){
      c += max(0, l - nl - 1) + max(0, nr - r - 1);
      l = nl, r = nr;
      continue;
    }

    ans = (1ll * ans * c) % MOD;
    --c;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}