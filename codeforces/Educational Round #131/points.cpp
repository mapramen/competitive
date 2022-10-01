#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 3
#define N 200000
#define M (1 << 19)

bool present[N + 1];
ll null[B][B] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
ll identity[B][B] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
ll pls[B][B] = {{1, 2, 1}, {0, 1, 1}, {0, 0, 1}};
ll mns[B][B] = {{1, -2, 1}, {0, 1, -1}, {0, 0, 1}};
ll T[B][B];
ll lazy_value[M][B][B], value[M][B][B];

void Set(ll des[B][B], ll src[B][B]){
  for(int i = 0; i < B; ++i){
    for(int j = i; j < B; ++j){
      des[i][j] = src[i][j];
    }
  }
}

void Add(ll a[B][B], ll b[B][B], ll c[B][B]){
  for(int i = 0; i < B; ++i){
    for(int j = i; j < B; ++j){
      c[i][j] = a[i][j] + b[i][j];
    }
  }
}

void Multiply(ll a[B][B], ll b[B][B], ll c[B][B]){
  for(int i = 0; i < B; ++i){
    for(int j = i; j < B; ++j){
      ll ans = 0;
      for(int k = 0; k < B; ++k){
        ans += a[i][k] * b[k][j];
      }
      T[i][j] = ans;
    }
  }

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

void UpdateNode(int k, ll x[B][B]){
  Multiply(x, value[k], value[k]);
  Multiply(x, lazy_value[k], lazy_value[k]);
}

void LazyUpdateChildren(int k){
  UpdateNode(2 * k + 1, lazy_value[k]);
  UpdateNode(2 * k + 2, lazy_value[k]);
  Set(lazy_value[k], identity);
}

void Set(int k, int l, int r, int i, ll x[B][B]){
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

void Update(int k, int l, int r, int ql, int qr, ll x[B][B]){
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

    ll ans = (value[0][0][2] - value[0][1][2]) / 2;
    printf("%lld\n", ans);
  }

  return 0;
}