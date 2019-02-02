#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 24
#define N (1 << B)
#define L 3

char s[L + 1];
int dp[N];

int main(){
  int n, ans;

  scanf("%d", &n);
  for(int x = 1; x <= n; ++x){
    int mask = 0;
    scanf("%s", s);
    for(int i = 0; i < L; ++i)
      mask |= (1 << (s[i] - 'a'));
    dp[mask]++;
  }

  for(int i = 0; i < B; i++){
    for(int mask = 0; mask < N; mask++){
      if((mask & (1 << i)) == 0)
        dp[(mask | (1 << i))] += dp[mask];
    }
  }

  ans = 0;
  for(int mask = 0; mask < N; ++mask){
    int ansx = n - dp[mask];
    ans ^= (ansx * ansx);
  }

  printf("%d\n", ans);

  return 0;
}
