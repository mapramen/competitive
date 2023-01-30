#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

ll T2[N], T1[N], T0[N];

void Update(ll T[], int i, ll x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

void Update(ll T[], int l, int r, ll val){
  Update(T, l, val);
  Update(T, r + 1, -val);
}

void Update(int l, int r){
  Update(T2, l, r, 1);
  Update(T1, l, r, 3 - 2 * l);
  Update(T0, l, r, 1ll * l * l - 3 * l + 2);
  Update(T0, r + 1, 1ll * (r - l + 1) * (r - l + 2));
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll Query(int i){
  return (Query(T2, i) * i * i + Query(T1, i) * i + Query(T0, i)) / 2;
}

ll Query(int l, int r){
  return Query(r) - Query(l - 1);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if(t == 0){
      Update(l, r);
    }
    else{
      printf("%lld\n", Query(l, r));
    }
  }

  return 0;
}