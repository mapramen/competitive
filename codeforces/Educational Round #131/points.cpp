#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 6
#define N 200000
#define M (1 << 19)

bool present[N + 1];
ll null[B] = {0, 0, 0, 0, 0, 0};
ll identity[B] = {1, 0, 0, 1, 0, 1};
ll pls[B] = {1, 2, 1, 1, 1, 1};
ll mns[B] = {1, -2, 1, 1, -1, 1};
ll T[B];
ll lazy_value[M][B], value[M][B];

bool IsSame(ll a[B], ll b[B]){
  for(int i = 0; i < B; ++i){
    if(a[i] != b[i]){
      return false;
    }
  }
  return true;
}

void Set(ll des[B], ll src[B]){
  for(int i = 0; i < B; ++i){
    des[i] = src[i];
  }
}

void Add(ll a[B], ll b[B], ll c[B]){
  for(int i = 0; i < B; ++i){
    c[i] = a[i] + b[i];
  }
}

void Multiply(ll a[B], ll b[B], ll c[B]){
  T[0] = a[0] * b[0];
  T[1] = a[0] * b[1] + a[1] * b[3];
  T[2] = a[0] * b[2] + a[1] * b[4] + a[2] * b[5];
  T[3] = a[3] * b[3];
  T[4] = a[3] * b[4] + a[4] * b[5];
  T[5] = a[5] * b[5];

  Set(c, T);
}

void Combine(int k){
  Add(value[2 * k + 1], value[2 * k + 2], value[k]);
}

void BuildSegmentTree(int k, int l, int r){
  if(l != r){
    int mid = (l + r) / 2;
    BuildSegmentTree(2 * k + 1, l, mid);
    BuildSegmentTree(2 * k + 2, mid + 1, r);
    Combine(k);
  }
  else{
    present[l] = false;
    Set(value[k], null);
  }
  Set(lazy_value[k], identity);
}

void UpdateNode(int k, ll x[B]){
  if(IsSame(x, identity)){
    return;
  }
  Multiply(x, value[k], value[k]);
  Multiply(x, lazy_value[k], lazy_value[k]);
}

void LazyUpdateChildren(int k){
  if(IsSame(lazy_value[k], identity)){
    return;
  }
  UpdateNode(2 * k + 1, lazy_value[k]);
  UpdateNode(2 * k + 2, lazy_value[k]);
  Set(lazy_value[k], identity);
}

void Set(int k, int l, int r, int i, ll x[B]){
  if(i < l || r < i){
    return;
  }

  if(i == l && r == i){
    Set(value[k], x);
    Multiply(lazy_value[k], value[k], value[k]);
    return;
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  Set(2 * k + 1, l, mid, i, x);
  Set(2 * k + 2, mid + 1, r, i, x);

  Combine(k);
}

void Update(int k, int l, int r, int ql, int qr, ll x[B]){
  if(qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return;
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, ql, qr, x);
  Update(2 * k + 2, mid + 1, r, ql, qr, x);
  Combine(k);
}

int main(){
  int q, d;
  scanf("%d%d", &q, &d);

  BuildSegmentTree(0, 1, N);

  while(q--){
    int i;
    scanf("%d", &i);

    present[i] = !present[i];

    if(present[i]){
      Update(0, 1, N, i - d, i - 1, pls);
      Set(0, 1, N, i, identity);
    }
    else{
      Update(0, 1, N, i - d, i - 1, mns);
      Set(0, 1, N, i, null);
    }

    ll ans = (value[0][2] - value[0][4]) / 2;
    printf("%lld\n", ans);
  }

  return 0;
}