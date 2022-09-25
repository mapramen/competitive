#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M 5000001

bool present[M];
int dp[M], c[M];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= m; ++i){
    present[i] = false;
    dp[i] = i;
    c[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    present[x] = true;
    c[x] = 1;
  }

  int mn = 0;
  for( ; !present[mn]; ++mn);

  int ans = m;
  for(int i = m, j = m; i != 0; --i){
    for(int x = i; x <= m; x += i){
      if(x / i < i){
        continue;
      }
      
      if(present[x]){
        --c[dp[x]];
      }
      
      dp[x] = min(dp[x], dp[x / i]);
      
      if(present[x]){
        ++c[dp[x]];
      }
    }

    if(i > mn){
      continue;
    }

    for( ; c[j] == 0; --j);
    ans = min(ans, j - i);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}