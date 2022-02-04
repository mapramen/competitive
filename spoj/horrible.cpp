#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

ll T1[N], T2[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    T1[i] = 0, T2[i] = 0;
  }
}

void Update(ll T[], int n, int i, ll x){
  for( ; i <= n; i += (i & -i)){
    T[i] += x;
  }
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void Update(int n, int l, int r, int val){
  Update(T1, n, l, val);
  Update(T1, n, r + 1, -val);

  Update(T2, n, l, -1ll * (l - 1) * val);
  Update(T2, n, r + 1, 1ll * r * val);
}

ll Query(int i){
  ll a = Query(T1, i), b = Query(T2, i);
  return a * i + b;
}

ll Query(int l, int r){
  return Query(r) - Query(l - 1);
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  while(m--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if(t == 0){
      int val;
      scanf("%d", &val);
      Update(n, l, r, val);
    }
    else{
      printf("%lld\n", Query(l, r));
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}