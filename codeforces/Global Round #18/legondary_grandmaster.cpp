#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001
#define MOD 1000000007

char S[N], T[N];
pii dp[N][N][2][2];

void CharacteristicTransform(int n, char s[]){
  for(int i = 1; i < n; i += 2){
    char c = s[i];
    if(c == '?'){
      continue;
    }

    s[i] = c == '0' ? '1' : '0';
  }
}

bool IsInvalid(int x, char c){
  return (x == 0 && c == '1') || (x == 1 && c == '0');
}

pii DP(int i, int j, int x, int y){
  if(IsInvalid(x, S[i - 1]) || IsInvalid(y, T[j - 1])){
    return {0, 0};
  }

  if(dp[i][j][x][y].first != INT_MIN){
    return dp[i][j][x][y];
  }

  int cnt = 0, ans = 0;
  if(x == y){
    for(int nx = 0; nx < 2; ++nx){
      for(int ny = 0; ny < 2; ++ny){
        auto [cntx, ansx] = DP(i - 1, j - 1, nx, ny);
        cnt = (cnt + cntx) % MOD;
        ans = (ans + ansx) % MOD;
      }
    }
    ans = (ans + 1ll * (x == 1) * cnt * abs(i - j)) % MOD;
  }
  else if(x == 0){
    for(int nx = 0; nx < 2; ++nx){
      auto [cntx, ansx] = DP(i - 1, j, nx, y);
      cnt = (cnt + cntx) % MOD;
      ans = (ans + ansx) % MOD;
    }
  }
  else {
    for(int ny = 0; ny < 2; ++ny){
      auto [cntx, ansx] = DP(i, j - 1, x, ny);
      cnt = (cnt + cntx) % MOD;
      ans = (ans + ansx) % MOD;
    }
  }

  dp[i][j][x][y] = {cnt, ans};
  return {cnt, ans};
}

int Solve(){
  int n;
  scanf("%d%s%s", &n, S, T);

  CharacteristicTransform(n, S);
  CharacteristicTransform(n, T);

  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= n; ++j){
      for(int x = 0; x < 2; ++x){
        for(int y = 0; y < 2; ++y){
          dp[i][j][x][y] = {i == 0 || j == 0 ? 0 : INT_MIN, 0};
        }
      }
    }
  }

  dp[0][0][0][0] = {1, 0};
 
  for(int i = 1, x = 0; i <= n; ++i){
    x += (S[i - 1] == '1');
    dp[i][0][0][0] = {x == 0, 0};
  }
 
  for(int j = 1, y = 0; j <= n; ++j){
    y += (T[j - 1] == '1');
    dp[0][j][0][0] = {y == 0, 0};
  }

  int ans = 0;
  for(int x = 0; x < 2; ++x){
    for(int y = 0; y < 2; ++y){
      ans = (ans + DP(n, n, x, y).second) % MOD;
    }
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