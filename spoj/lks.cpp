#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2000001

int dp[N];

int main(){
  int m, n;
  scanf("%d%d", &m, &n);

  for(int i = 0; i < N; ++i){
    dp[i] = INT_MIN;
  }

  dp[0] = 0;
  while(n--){
    int w, v;
    scanf("%d%d", &v, &w);

    if(w > m){
      continue;
    }

    for(int i = m, j = m - w; j != -1; --i, --j){
      if(dp[j] != INT_MIN){
        dp[i] = max(dp[i], dp[j] + v);
      }
    }
  }

  printf("%d\n", *max_element(dp, dp + m + 1));

  return 0;
}