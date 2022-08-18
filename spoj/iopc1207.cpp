#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 18)
#define B 3

int a[B], b[B], c[B], L[B], R[B];
int zeros[B][M], ones[B][M], lazy_value[B][M];

void Combine(int zeros[M], int ones[M], int lazy_value[M], int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  zeros[k] = zeros[k1] + zeros[k2];
  ones[k] = ones[k1] + ones[k2];
  lazy_value[k] = 0;
}

void BuildSegmentTree(int zeros[M], int ones[M], int lazy_value[M], int k, int l, int r){
  if(l == r){
    zeros[k] = 1, ones[k] = 0, lazy_value[k] = 0;
  }
  else{
    int mid = (l + r) / 2;
    BuildSegmentTree(zeros, ones, lazy_value, 2 * k + 1, l, mid);
    BuildSegmentTree(zeros, ones, lazy_value, 2 * k + 2, mid + 1, r);
    Combine(zeros, ones, lazy_value, k);
  }
}

void UpdateNode(int zeros[M], int ones[M], int lazy_value[M], int k, int val){
  if(val == 0){
    return;
  }

  swap(zeros[k], ones[k]);
  lazy_value[k] ^= val;
}

void LazyUpdateChildren(int zeros[M], int ones[M], int lazy_value[M], int k){
  UpdateNode(zeros, ones, lazy_value, 2 * k + 1, lazy_value[k]);
  UpdateNode(zeros, ones, lazy_value, 2 * k + 2, lazy_value[k]);
  lazy_value[k] = 0;
}

void Update(int zeros[M], int ones[M], int lazy_value[M], int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(zeros, ones, lazy_value, k, 1);
    return;
  }

  LazyUpdateChildren(zeros, ones, lazy_value, k);

  int mid = (l + r) / 2;
  Update(zeros, ones, lazy_value, 2 * k + 1, l, mid, ql, qr);
  Update(zeros, ones, lazy_value, 2 * k + 2, mid + 1, r, ql, qr);
  Combine(zeros, ones, lazy_value, k);
}

int Query(int zeros[M], int ones[M], int lazy_value[M], int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return 0;
  }

  if(ql <= l && r <= qr){
    return ones[k];
  }

  LazyUpdateChildren(zeros, ones, lazy_value, k);

  int mid = (l + r) / 2;
  int ans = Query(zeros, ones, lazy_value, 2 * k + 1, l, mid, ql, qr) + Query(zeros, ones, lazy_value, 2 * k + 2, mid + 1, r, ql, qr);
  Combine(zeros, ones, lazy_value, k);

  return ans;
}

void Reset(){
  for(int k = 0; k < B; ++k){
    BuildSegmentTree(zeros[k], ones[k], lazy_value[k], 0, 1, c[k]);
  }
}

ll GetCount(int mask){
  ll ans = 1;
  for(int k = 0; k < B; ++k){
    ans *= (((mask & (1 << k)) != 0) ? a[k] : b[k]);
  }
  return ans;
}

void Solve(){
  for(int k = 0; k < B; ++k){
    scanf("%d", &c[k]);
  }

  Reset();

  int q;
  scanf("%d", &q);

  while(q--){
    int t;
    scanf("%d", &t);

    if(t < 3){
      int l, r;
      scanf("%d%d", &l, &r);
      ++l, ++r;
      Update(zeros[t], ones[t], lazy_value[t], 0, 1, c[t], l, r);
    }
    else{
      for(int k = 0; k < B; ++k){
        scanf("%d", &L[k]);
        ++L[k];
      }

      for(int k = 0; k < B; ++k){
        scanf("%d", &R[k]);
        ++R[k];
      }

      for(int k = 0; k < B; ++k){
        a[k] = Query(zeros[k], ones[k], lazy_value[k], 0, 1, c[k], L[k], R[k]);
        b[k] = R[k] - L[k] + 1;
      }

      ll ans = 0;
      for(int mask = 1; mask < (1 << B); ++mask){
        int bits = __builtin_popcount(mask);
        int mul = (1 << (bits - 1));
        ll ansx = mul * GetCount(mask);
        ans += (bits % 2 == 1 ? ansx : -ansx);
      }

      printf("%lld\n", ans);
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