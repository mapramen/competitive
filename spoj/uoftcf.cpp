#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51
#define INF 1000

char s[N];
int T[N][N], dp[N][N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      dp[i][j] = 0;
    }
  }
}

void UpdateDP(int n, int i, int j, int val){
  if(val < 0 || i <= 0 || i > n || j <= 0 || j > n || i == j || s[i - 1] == '#' || s[j - 1] == '#'){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  dp[i][j] = max(dp[i][j], val + (j - i == 1));
}

void UpdateDP(int n){
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      T[i][j] = dp[i][j];
      dp[i][j] = -INF;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      for(int di = -1; di < 2; ++di){
        for(int dj = -1; dj < 2; ++dj){
          UpdateDP(n, i + di, j + dj, T[i][j]);
        }
      }
    }
  }
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(m);

  while(n--){
    scanf("%s", s);
    UpdateDP(m);
  }

  int ans = -INF;
  for(int i = 1; i <= m; ++i){
    for(int j = i + 1; j <= m; ++j){
      ans = max(ans, dp[i][j]);
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int ans = Solve();
    printf("%s\n", ans < 0 ? "Detour" : to_string(ans).c_str());
  }
  return 0;
}