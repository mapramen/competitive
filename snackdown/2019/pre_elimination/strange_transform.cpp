#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 9
#define N 200002
#define M (1 << B)
#define K (1 << (2 * B))

int dp[M][N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &dp[0][i]);
  }

  for(int k = 1; k < M; ++k){
    for(int i = n; i > 0; --i){
      dp[k][i] = (dp[k - 1][i] ^ dp[k - 1][i + 1]);
    }
  }

  while(q--){
    int k, i, x;
    scanf("%d%d", &k, &i);

    k %= K;
    x = ((k >> B) << B), k ^= x;

    int ans = dp[k][i];
    for(int y = x; y; y = ((y - 1) & x)){
      if(i + y <= n){
        ans ^= dp[k][i + y];
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
