#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 27
#define M (1 << 18)

char op[10];
int T[M][B], c[B];

void Update(int c[B], int x){
  for(int k = 0; k < B; ++k){
    c[k] = (x & (1 << k)) != 0;
  }
}

void Combine(int a[B], int b[B], int c[B]){
  for(int k = 0; k < B; ++k){
    c[k] = a[k] + b[k];
  }
}

void Update(int k, int l, int r, int i, int x){
  if(i < l || r < i){
    return;
  }

  if(i == l && r == i){
    Update(T[k], x);
    return;
  }

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, i, x);
  Update(2 * k + 2, mid + 1, r, i, x);
  Combine(T[2 * k + 1], T[2 * k + 2], T[k]);
}

void Reset(){
  for(int k = 0; k < B; ++k){
    c[k] = 0;
  }
}

void Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    Combine(T[k], c, c);
    return;
  }

  int mid = (l + r) / 2;
  Query(2 * k + 1, l, mid, ql, qr);
  Query(2 * k + 2, mid + 1, r, ql, qr);
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Update(0, 1, n, i, x);
  }

  while(q--){
    int t;
    scanf("%d", &t);

    if(t == 1){
      int i, x;
      scanf("%d%d", &x, &i);
      Update(0, 1, n, i, x);
    }
    else{
      int l, r;
      scanf("%s%d%d", op, &l, &r);

      if(l == r){
        printf("0\n");
        continue;
      }

      Reset();
      Query(0, 1, n, l, r);

      ll ans = 0;
      for(int k = 0, m = r - l + 1; k < B; ++k){
        ll cnt = 0;
        if(op[0] == 'O'){
          cnt = (1ll * m * (m - 1) - 1ll * (m - c[k]) * (m - c[k] - 1)) / 2;
        }
        else if(op[0] == 'A'){
          cnt = 1ll * c[k] * (c[k] - 1) / 2;
        }
        else{
          cnt = 1ll * c[k] * (m - c[k]);
        }
        ans += cnt * (1 << k);
      }

      printf("%lld\n", ans);
    }
  }

  return 0;
}