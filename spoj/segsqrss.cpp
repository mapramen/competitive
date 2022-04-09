#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 18)

ll sum_squares[M], sum[M];
int cnt[M], add_lazy_value[M];
bool set_lazy_value[M];

void Reset(int k, int l, int r){
  if(l != r){
    int mid = (l + r) / 2;
    Reset(2 * k + 1, l, mid);
    Reset(2 * k + 2, mid + 1, r);
  }

  sum_squares[k] = 0, sum[k] = 0, cnt[k] = r - l + 1, add_lazy_value[k] = 0, set_lazy_value[k] = false;
}

void Update(int k, bool set_value, int add_value){
  if(set_value){
    sum_squares[k] = 0, sum[k] = 0, add_lazy_value[k] = 0;
    set_lazy_value[k] = true;
  }

  if(add_value == 0){
    return;
  }

  sum_squares[k] += 2 * sum[k] * add_value + 1ll * cnt[k] * add_value * add_value;
  sum[k] += 1ll * cnt[k] * add_value;
  add_lazy_value[k] += add_value;
}

void LazyUpdateChildren(int k){
  Update(2 * k + 1, set_lazy_value[k], add_lazy_value[k]);
  Update(2 * k + 2, set_lazy_value[k], add_lazy_value[k]);
  set_lazy_value[k] = false, add_lazy_value[k] = 0;
}

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  sum_squares[k] = sum_squares[k1] + sum_squares[k2];
  sum[k] = sum[k1] + sum[k2];
}

void Update(int k, int l, int r, int ql, int qr, int set_value, int add_value){
  if(r < ql || qr < l){
    return;
  }

  if(ql <= l && r <= qr){
    Update(k, set_value, add_value);
    return;
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, ql, qr, set_value, add_value);
  Update(2 * k + 2, mid + 1, r, ql, qr, set_value, add_value);
  Combine(k);
}

ll Query(int k, int l, int r, int ql, int qr){
  if(r < ql || qr < l){
    return 0ll;
  }

  if(ql <= l && r <= qr){
    return sum_squares[k];
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  ll ans = Query(2 * k + 1, l, mid, ql, qr) + Query(2 * k + 2, mid + 1, r, ql, qr);
  Combine(k);

  return ans;
}

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  Reset(0, 1, n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Update(0, 1, n, i, i, true, x);
  }

  while(q--){
    int t, ql, qr;
    scanf("%d%d%d", &t, &ql, &qr);

    if(t < 2){
      int x;
      scanf("%d", &x);
      Update(0, 1, n, ql, qr, t == 0, x);
    }
    else{
      printf("%lld\n", Query(0, 1, n, ql, qr));
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d:\n", k);
    Solve();
  }
  return 0;
}