#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

ll dp[N][N], s[N], inf = LLONG_MAX / 2;
int a[N];
pii b[N];

void DivideAndConquer(int i, int c, int l, int r, int low, int high){
  if(l > r || low > high)
    return ;

  if(low == high){
    for(int k = low; l <= r; l++)
      dp[i][l] = min(dp[i][l], dp[i - 1][k] + s[l] - s[k]);
    return ;
  }

  int mid = l + (r - l) / 2, k = high + 1;

  for(int x = max(low, mid - c); x <= min(mid, high); x++){
    ll dpx = dp[i - 1][x] + s[mid] - s[x];
    if(dpx < dp[i][mid]){
      dp[i][mid] = dpx;
      k = x;
    }
  }

  DivideAndConquer(i, c, l, mid - 1, low, min(k, high));
  DivideAndConquer(i, c, mid + 1, r, k, high);
}

int main(){
  int n, m;
  ll ans;

  scanf("%d%d", &m, &n);

  for(int j = 1; j <= m; j++)
    scanf("%d", &a[j]);

  for(int i = 1; i <= n; i++)
    scanf("%d%d", &b[i].first, &b[i].second);

  sort(b + 1, b + n + 1);
  sort(a + 1, a + m + 1);

  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= m; j++)
      dp[i][j] = inf;

  dp[0][0] = 0;

  for(int i = 1; i <= n; i++){
    int c, p;
    tie(p, c) = b[i];

    for(int j = 1; j <= m; j++){
      s[j] = abs(p - a[j]);
      s[j] += s[j - 1];
    }

    DivideAndConquer(i, c, 1, m, 0, m);

    for(int j = 0; j <= m; j++)
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
  }

  ans = dp[n][m];

  if(ans == inf)
    ans = -1;

  printf("%lld\n", ans);

  return 0;
}
