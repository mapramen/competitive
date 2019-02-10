#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501

int dp[2][N], s[N], a[N], inf = 1E9;
char t[N];

void Reset(int a[]){
  for(int i = 0; i < N; ++i)
    a[i] = inf;
}

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  int cur = 0;
  while(n--){
    scanf("%s", t);

    for(int i = 1; i <= m; ++i)
      s[i] = s[i - 1] + (t[i - 1] - '0');

    Reset(a);
    a[s[m]] = 0;
    for(int i = 1; i <= m; ++i){
      if(t[i - 1] == '0')
        continue;
      for(int j = i; j <= m; ++j){
        if(t[j - 1] == '0')
          continue;
        int x = s[m] - s[j] + s[i - 1];
        a[x] = min(a[x], j - i + 1);
      }
    }

    int nxt = 1 - cur;
    Reset(dp[nxt]);
    for(int i = k; i > -1; --i)
      for(int j = 0; j <= i; ++j)
        dp[nxt][i] = min(dp[nxt][i], dp[cur][i - j] + a[j]);

    cur = 1 - cur;
  }

  int ans = inf;
  for(int i = 0; i <= k; ++i)
    ans = min(ans, dp[cur][i]);

  printf("%d\n", ans);

  return 0;
}
