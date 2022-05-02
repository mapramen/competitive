#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 202

char s[N][N];
int dp_left[N][N], dp_right[N][N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  for(int i = 0; i <= n + 1; ++i){
    for(int j = 0; j <= m + 1; ++j){
      dp_left[i][j] = INT_MIN, dp_right[i][j] = INT_MIN;
    }
  }

  dp_left[0][1] = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(s[i - 1][j - 1] == '#'){
        continue;
      }
      dp_right[i][j] = (s[i - 1][j - 1] == 'T') + max(dp_left[i - 1][j], dp_right[i][j - 1]);
    }

    for(int j = m; j >= 1; --j){
      if(s[i - 1][j - 1] == '#'){
        continue;
      }
      dp_left[i][j] = (s[i - 1][j - 1] == 'T') + max(dp_right[i - 1][j], dp_left[i][j + 1]);
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      ans = max(ans, max(dp_left[i][j], dp_right[i][j]));
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