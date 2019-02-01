#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define M 6
#define B 19

int m, a[N], temp[M], ans[M];

void FillIdentityMapping(int a[]){
  for(int i = 0; i <= m; ++i){
    a[i] = i;
  }
}

void FillBaseMapping(int n, int a[]){
  for(int i = 0; i < m; ++i){
    a[i] = 1 + i;
  }
  a[m] = (n == 1) ? m : 0;
}

//----------------------------------------- Segment Tree -----------------------------------------//
int f0[(1 << B)][M], f1[(1 << B)][M], lazyValue[(1 << B)];

void Combine(int a[], int b[], int c[]){
  for(int i = 0; i <= m; ++i){
    temp[i] = a[b[i]];
  }
  for(int i = 0; i <= m; ++i){
    c[i] = temp[i];
  }
}

void Combine(int k){
  Combine(f0[2 * k + 1], f0[2 * k + 2], f0[k]);
  Combine(f1[2 * k + 1], f1[2 * k + 2], f1[k]);
}

void SwapMapping(int a[], int b[]){
  for(int i = 0; i <= m; ++i){
    swap(a[i], b[i]);
  }
}

void BuildSegmentTree(int k, int l, int r){
  lazyValue[k] = 0;
  if(l == r){
    FillBaseMapping(a[l], f0[k]);
    FillBaseMapping(1 - a[l], f1[k]);
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
}

void UpdateNode(int k, int val){
  if(val == 0){
    return ;
  }
  SwapMapping(f0[k], f1[k]);
  lazyValue[k] = 1 - lazyValue[k];
}

void LazyUpdateChildren(int k){
  if(lazyValue[k] == 0){
    return ;
  }
  UpdateNode(2 * k + 1, lazyValue[k]);
  UpdateNode(2 * k + 2, lazyValue[k]);
  lazyValue[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(qr < l || r < ql){
    return ;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  Combine(k);
}

void Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return ;
  }

  if(ql <= l && r <= qr){
    Combine(f0[k], ans, ans);
    return ;
  }

  LazyUpdateChildren(k);
  Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Query(2 * k + 1, l, (l + r) / 2, ql, qr);
  Combine(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, q;

  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= n; ++i){
    ll x;
    scanf("%lld", &x);
    a[i] = (x - 1) % 2;
  }

  BuildSegmentTree(0, 1, n);

  while(q--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if(t == 1){
      ll x;
      scanf("%lld", &x);
      x %= 2;
      if(x){
        Update(0, 1, n, l, r, (int)x);
      }
    }
    else{
      FillIdentityMapping(ans);
      Query(0, 1, n, l, r);
      printf("%d\n", 1 + (ans[m] == 0));
    }
  }

  return 0;
}
