#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define B 2
#define M (1 << 18)

ll a[N][B][B], T[M][B][B], t[B][B], dp[B][B], qa1[B][B], qa2[B][B], q1[B][B], q2[B][B];

void Initialize(ll a[B][B], ll c[B][B]){
  for(int x = 0; x < B; ++x){
    for(int y = 0; y < B; ++y){
      c[x][y] = abs(a[0][x] - a[1][y]);
    }
  }
}

void Combine(ll a[B][B], ll b[B][B], ll c[B][B]){
  for(int i = 0; i < B; ++i){
    for(int j = 0; j < B; ++j){
      ll ans = LLONG_MAX;
      for(int k = 0; k < B; ++k){
        ans = min(ans, a[i][k] + 1 + b[k][j]);
      }
      t[i][j] = ans;
    }
  }

  for(int i = 0; i < B; ++i){
    for(int j = 0; j < B; ++j){
      c[i][j] = t[i][j];
    }
  }
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    Initialize(a[l], T[k]);
  }
  else{
    int mid = (l + r) / 2;
    BuildSegmentTree(2 * k + 1, l, mid);
    BuildSegmentTree(2 * k + 2, mid + 1, r);
    Combine(T[2 * k + 1], T[2 * k + 2], T[k]);
  }
}

void Query(int k, int l, int r, int ql, int qr){
  if(qr < ql || r < l || qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    Combine(dp, T[k], dp);
    return;
  }

  int mid = (l + r) / 2;
  Query(2 * k + 1, l, mid, ql, qr);
  Query(2 * k + 2, mid + 1, r, ql, qr);
}

int GetHorizontalCellNumber(int n, int x, int y){
  return x;
}

int GetVerticalCellNumber(int n, int x, int y){
  return n + n - y;
}

int GetCellNumber(int x, int y){
  int n = max(x, y);
  return y == n ? GetHorizontalCellNumber(n, x, y) : GetVerticalCellNumber(n, x, y);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i < n; ++i){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
    
    a[i][1][0] = GetHorizontalCellNumber(i, x1, y1);
    a[i][1][1] = GetVerticalCellNumber(i, x2, y2);

    a[i + 1][0][0] = GetHorizontalCellNumber(i + 1, x1, y1 + 1);
    a[i + 1][0][1] = GetVerticalCellNumber(i + 1, x2 + 1, y2);
  }

  a[1][0][0] = 1, a[1][0][1] = 1;
  a[n][1][0] = a[n][0][0], a[n][1][1] = a[n][0][1];

  BuildSegmentTree(0, 1, n);

  int q;
  scanf("%d", &q);

  while(q--){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &y1, &x1, &y2, &x2);

    int n1 = max(x1, y1), n2 = max(x2, y2);
    if(n1 > n2){
      swap(x1, x2), swap(y1, y2), swap(n1, n2);
    }

    if(n1 == n2){
      printf("%d\n", abs(GetCellNumber(x1, y1) - GetCellNumber(x2, y2)));
      continue;
    }

    qa1[0][0] = qa1[0][1] = GetCellNumber(x1, y1);
    qa1[1][0] = a[n1][1][0], qa1[1][1] = a[n1][1][1];

    qa2[0][0] = a[n2][0][0], qa2[0][1] = a[n2][0][1];
    qa2[1][0] = qa2[1][1] = GetCellNumber(x2, y2);

    Initialize(qa1, dp);
    Initialize(qa2, q2);

    if(n1 + 1 != n2){
      Query(0, 1, n, n1 + 1, n2 - 1);
    }

    Combine(dp, q2, dp);

    ll ans = LLONG_MAX;
    for(int x = 0; x < B; ++x){
      for(int y = 0; y < B; ++y){
        ans = min(ans, dp[x][y]);
      }
    }

    printf("%lld\n", ans);
  }
  return 0;
}