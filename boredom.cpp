#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int n;
vector< vector<int> > A(N);

ll nC2(int x){
  return 1ll * x * (x - 1) / 2;
}

int GetCompressedValue(vector<int>& C, int x){
  int cx = lower_bound(C.begin(), C.end(), x) - C.begin();
  cx -= (C[cx] != x);
  return cx;
}

int Query(int i, int j){
  int ans = 0;
  for(i = min(i, n); i > 0; i -= (i & -i)){
    if(j < A[i].front())
      continue;
    if(j > A[i].back())
      ans += A[i].size();
    else{
      int cj = GetCompressedValue(A[i], j);
      ans += (cj + 1);
    }
  }
  return ans;
}

ll QueryRectangle(int x1, int y1, int x2, int y2){
  int c = Query(x2, y2) + Query(x1 - 1, y1 - 1) - Query(x2, y1 - 1) - Query(x1 - 1, y2);
  ll ans = 1ll * c * (c - 1) / 2;
  return ans;
}

ll Query(int x1, int y1, int x2, int y2){
  ll ans = nC2(x1 - 1) + nC2(n - x2) + nC2(y1 - 1) + nC2(n - y2);
  ans -= QueryRectangle(1, 1, x1 - 1, y1 - 1);
  ans -= QueryRectangle(1, y2 + 1, x1 - 1, n);
  ans -= QueryRectangle(x2 + 1, 1, n, y1 - 1);
  ans -= QueryRectangle(x2 + 1, y2 + 1, n, n);
  ans = 1ll * n * (n - 1) / 2 - ans;
  return ans;
}

int main(){
  int q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    for(int k = i; k <= n; k += (k & -k))
      A[k].PB(j);
  }

  for(int i = 1; i <= n; ++i){
    sort(A[i].begin(), A[i].end());
  }

  while(q--){
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%lld\n", Query(x1, y1, x2, y2));
  }

  return 0;
}
