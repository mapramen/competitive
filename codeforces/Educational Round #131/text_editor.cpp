#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5002
#define INF 1E6

char s[N], t[N];
int dp_prefix[N][N], dp_suffix[N][N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  scanf("%s%s", s, t);

  for(int i = 0; i <= n + 1; ++i){
    for(int j = 0; j <= n + 1; ++j){
      dp_prefix[i][j] = INF, dp_suffix[i][j] = INF;
    }
  }

  dp_prefix[0][0] = 0;
  for(int i = 1; i <= n; ++i){
    dp_prefix[i][0] = 1 + 2 * i;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(s[i - 1] == t[j - 1]){
        dp_prefix[i][j] = min(1 + dp_prefix[i - 1][j - 1], 2 + dp_prefix[i - 1][j]);
      }
      else{
        dp_prefix[i][j] = 2 + dp_prefix[i - 1][j];
      }
    }
  }

  for(int i = 1; i <= n + 1; ++i){
    dp_suffix[i][m + 1] = n - i + 1;
  }

  for(int i = n; i != 0; --i){
    for(int j = m; j != 0;)
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}