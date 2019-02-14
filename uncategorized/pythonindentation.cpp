#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5005
#define MOD 1000000007

char s[N];
int dp[N][N];

int main(){
  int n;
  char a = 's', b;

  scanf("%d", &n);

  dp[0][0] = 1;
  for(int i = 1; i <= n; ++i){
    scanf("%s", s);
    b = s[0];

    if(a == 'f'){
      for(int k = 1; k <= n; ++k)
        dp[i][k] = (dp[i][k] + dp[i - 1][k - 1]) % MOD;
    }
    else{
      for(int k = n; k > -1; --k)
        dp[i][k] = (dp[i][k + 1] + dp[i - 1][k]) % MOD;
    }

    a = b;
  }

  int ans = 0;
  for(int k = 0; k <= n; ++k)
    ans = (ans + dp[n][k]) % MOD;

  printf("%d\n", ans);

  return 0;
}
