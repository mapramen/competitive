#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5002

char s[N], t[N];
int max_prefix[N], max_suffix[N], dp[N][N];

void FillMaxPrefix(int n, int m, int max_prefix[]){
  max_prefix[0] = 0;
  for(int i = 1, j = 0; i <= n; ++i){
    if(j != m){
      j += (t[j] == s[i - 1]);
    }
    max_prefix[i] = j;
  }
}

void FillMaxSuffix(int n, int m, int max_suffix[]){
  reverse(s, s + n);
  reverse(t, t + m);

  FillMaxPrefix(n, m, max_suffix);

  for(int i = 0; i <= n; ++i){
    max_suffix[i] = m + 1 - max_suffix[i];
  }

  for(int i = 0, j = n + 1; i < j; ++i, --j){
    swap(max_suffix[i], max_suffix[j]);
  }

  reverse(s, s + n);
  reverse(t, t + m);
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  scanf("%s%s", s, t);

  for(int i = 0; i <= n + 1; ++i){
    for(int j = 0; j <= m + 1; ++j){
      dp[i][j] = 0;
    }
    max_prefix[i] = 0, max_suffix[i] = 0;
  }

  FillMaxPrefix(n, m, max_prefix);
  FillMaxSuffix(n, m, max_suffix);

  if(max_prefix[n] != m){
    return -1;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(s[i - 1] == t[j - 1]){
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
    }
  }

  int ans = n + n - m;
  for(int i = 1; i <= n + 1; ++i){
    for(int j = 1; j <= m + 1; ++j){
      if(j < max_suffix[i] || max_prefix[i - 1] < j - 1){
        continue;
      }
      int ansx = (n + 1 - i) + (i - 1 - dp[i - 1][j - 1]) + (i - j);
      if(i - 1 != dp[i - 1][j - 1]){
        ++ansx;
      }
      ans = min(ans, ansx);
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