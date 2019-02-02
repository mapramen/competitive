#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300010
#define LOGN 19
#define inf 1000000007

int a[N], b[N], lg[N], T[LOGN][N];
vector<int> v;

int GetCompressedValue(int x){
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void PreProcess(int n){
  v.PB(-inf);
  v.PB(inf);

  for(int i = 1; i <= n; ++i)
    v.PB(a[i]);

  sort(v.begin(), v.end());

  for(int i = 1; i <= n; ++i){
    int j = GetCompressedValue(a[i]);
    T[0][j] = b[i] + 1;
  }

  for(int i = 2; i < v.size(); ++i)
    lg[i] = 1 + lg[(i / 2)];

  for(int k = 1; k < LOGN; ++k)
    for(int i = 0, j = i + (1 << (k - 1)); j < v.size(); ++i, ++j)
      T[k][i] = max(T[k - 1][i], T[k - 1][j]);
}

int RMQ(int i, int j){
  if(i > j)
    return -inf;

  int k = lg[j - i + 1];
  j -= ((1 << k) - 1);
  return max(T[k][i], T[k][j]);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%d%d", &a[i], &b[i]);

  PreProcess(n);

  while(q--){
    int x1, x2, y1, y2;
    ll ans = 0;

    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    if(x1 > x2)
      swap(x1, x2);

    if(y1 > y2)
      swap(y1, y2);

    int y = RMQ(GetCompressedValue(x1), GetCompressedValue(x2) - 1);

    if(y > y2)
      ans = 0ll + (y - y1) + (y - y2);
    else
      ans = 0ll + y2 - y1;

    ans += (0ll + x2 - x1);

    printf("%lld\n", ans);
  }

  return 0;
}
