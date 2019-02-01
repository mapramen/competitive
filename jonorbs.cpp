#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define K 1001

long double dp[K], eps = 1E-7;
pii queries[K];
int ans[K];

int main(){
  int k, q, qRem;

  scanf("%d%d", &k, &q);

  for(int i = 1; i <= q; i++){
    scanf("%d", &queries[i].first);
    queries[i].second = i;
    ans[i] = INT_MAX;
  }

  sort(queries + 1, queries + q + 1);
  dp[0] = 2000;

  int i = 1, day = 0;
  while(i <= q){
    ++day;
    for(int j = k; j > 0; j--)
      dp[j] = j * (dp[j - 1] + dp[j]) / k;
    dp[0] = 0;

    for( ; i <= q && dp[k] + eps > queries[i].first; i++)
      ans[queries[i].second] = day;
  }

  for(i = 1; i <= q; i++)
    printf("%d\n", ans[i]);
    
  return 0;
}
