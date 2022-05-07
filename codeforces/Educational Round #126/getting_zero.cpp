#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 32768

int dp[N];

int main(){
  for(int i = 1; i < N; ++i){
    dp[i] = 30;
  }

  for(int k = 0; k < 30; ++k){
    for(int i = 1; i < N; ++i){
      dp[i] = min(dp[i], 1 + min(dp[(i + 1) % N], dp[(2 * i) % N]));
    }
  }

  int n;
  scanf("%d", &n);

  while(n--){
    int i;
    scanf("%d", &i);
    printf("%d ", dp[i]);
  }
  printf("\n");
  
  return 0;
}