#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501
#define M 500 * 500 * 1

int n, m, k, q, S[N][N], a[M], b[M], c[M], inf = INT_MAX / 2;

bool Check(int t){
  for(int i = 1; i <= q; ++i)
    S[a[i]][b[i]] = (c[i] <= t);

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      S[i][j] += (S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1]);

  bool check = 0;
  for(int x1 = 1, x2 = x1 + k - 1; x2 <= n && check == 0; ++x1, ++x2)
    for(int y1 = 1, y2 = y1 + k - 1; y2 <= m && check == 0; ++y1, ++y2)
      check = ((S[x2][y2] + S[x1 - 1][y1 - 1] - S[x2][y1 - 1] - S[x1 - 1][y2]) == k * k);

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      S[i][j] = 0;

  return check;
}

int BinarySearch(){
  int x = 0, y = inf, z = y;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(mid))
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return z;
}

int main(){
  scanf("%d%d%d%d", &n, &m, &k, &q);

  for(int i = 1; i <= q; ++i)
    scanf("%d%d%d", &a[i], &b[i], &c[i]);

  int ans = BinarySearch();
  if(ans == inf)
    ans = -1;

  printf("%d\n", ans);

  return 0;
}
