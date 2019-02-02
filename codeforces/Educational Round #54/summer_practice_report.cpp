#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

int m, dp[N][2], x[N], y[N];

int Compute1(int x, int y, int p){
  if(x == 0){
    return m + 1;
  }
  --x, --y;
  int z = min(x, y);
  x -= z, y -= z;
  if(y <= 1ll * (1 + z) * (m - 1)){
    return 1 + max(0ll, x - (m - p) - 1ll * z * (m - 1));
  }
  else{
    return m + 1;
  }
}

int Compute2(int x, int y, int p){
  --y;
  int z = min(x, y);
  x -= z, y -= z;
  if(x <= (m - p) + 1ll * z * (m - 1)){
    return 1 + max(0ll, y - 1ll * z * (m - 1));
  }
  else{
    return m + 1;
  }
}

void Update(int i, int a, int x){
  if(x <= m){
    dp[i][a] = min(dp[i][a], x);
    dp[i][1 - a] = 0;
  }
}

void Compute(int i, int a, int x, int y){
  if(dp[i - 1][a] >= m){
    return ;
  }
  Update(i, a, Compute1(x - 1, y, dp[i - 1][a] + 1));
  Update(i, 1 - a, Compute2(x - 1, y, dp[i - 1][a] + 1));
}

int main(){
  int n;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &x[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &y[i]);
  }

  for(int i = 1; i <= n; ++i){
    dp[i][0] = m + 1, dp[i][1] = m + 1;
    Compute(i, 0, x[i], y[i]);
    Compute(i, 1, y[i], x[i]);
  }

  if(dp[n][0] <= m || dp[n][1] <= m){
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }

  return 0;
}
