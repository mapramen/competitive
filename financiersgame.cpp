#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< int, pii >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 4001
#define K 90

int n, p[N], dp1[N][2 * K][K], dp2[N][2 * K][K];

int Compute(int l, int r, int k, int x){
  if(r - l + 1 < k)
    return 0;

  int d = (n + 1) - (l + r) + K;

  if(x == 0){
    if(dp1[l][d][k] == INT_MIN){
      int ans = p[l + k - 1] - p[l - 1] + Compute(l + k, r, k, 1);

      if(r - l + 1 > k)
        ans = max(ans, p[l + k] - p[l - 1] + Compute(l + k + 1, r, k + 1, 1));

      dp1[l][d][k] = ans;
    }

    return dp1[l][d][k];
  }
  else{
    if(dp2[l][d][k] == INT_MIN){
      int ans = -(p[r] - p[r - k]) + Compute(l, r - k, k, 0);

      if(r - l + 1 > k)
        ans = min(ans, -(p[r] - p[r - k - 1]) + Compute(l, r - k - 1, k + 1, 0));

      dp2[l][d][k] = ans;
    }

    return dp2[l][d][k];
  }
}

int main(){
  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    scanf("%d", &p[i]);
    p[i] += p[i - 1];
  }

  for(int i = 0; i < N; i++)
    for(int j = 0; j < 2 * K; j++)
      for(int k = 0; k < K; k++)
        dp1[i][j][k] = dp2[i][j][k] = INT_MIN;

  printf("%d\n", Compute(1, n, 1, 0));

  return 0;
}
