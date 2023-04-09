#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 19)

int left_end_value[M], right_end_value[M];
ll dp[M][4], INF = 1E18;

void UpdateLeaf(int k, int x){
  left_end_value[k] = x, right_end_value[k] = x;
  dp[k][0] = INF, dp[k][1] = 0, dp[k][2] = 0, dp[k][3] = 0;
}

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;

  left_end_value[k] = left_end_value[k1];
  right_end_value[k] = right_end_value[k2];

  dp[k][0] = INF, dp[k][1] = INF, dp[k][2] = INF, dp[k][3] = INF;

  for(int x = 0; x < 4; ++x){
    for(int y = 0; y < 4; ++y){
      int z = (x & 2) | (y & 1);
      ll cost = dp[k1][x] + dp[k2][y] + (((x & 1) == 1 || (y & 2) == 2) ? right_end_value[k1] : 0);
      dp[k][z] = min(dp[k][z], cost);
    }
  }
}

void Update(int k, int l, int r, int i, int x){
  if(i < l || r < i){
    return;
  }

  if(l == i && r == i){
    UpdateLeaf(k, x);
    return;
  }

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, i, x);
  Update(2 * k + 2, mid + 1, r, i, x);
  Combine(k);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i < n; ++i){
    int x;
    scanf("%d", &x);
    Update(0, 1, n, i, x);
  }
  Update(0, 1, n, n, 0);

  int q;
  scanf("%d", &q);

  while(q--){
    int i, x;
    scanf("%d%d", &i, &x);
    Update(0, 1, n, i, x);
    printf("%lld\n", 2 * dp[0][0]);
  }

  return 0;
}