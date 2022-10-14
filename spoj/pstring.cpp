#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define B 26
#define M 10001

char s[N], t[M];
int f[N], transition[B][N], dp[2][N];

int ComputeFailure(int k, char c){
  while(k != 0 && s[k] != c){
    k = f[k];
  }
  return k + (s[k] == c);
}

int Solve(){
  if(scanf("%s%s", t, s) == EOF){
    exit(0);
  }

  int n = strlen(s), m = strlen(t);

  for(int k = 2; k <= n; ++k){
    f[k] = ComputeFailure(f[k - 1], s[k - 1]);
  }

  for(char c = 'a'; c <= 'z'; ++c){
    for(int i = 0; i < n; ++i){
      transition[c - 'a'][i] = ComputeFailure(i, c);
    }
  }

  int cur = 0;
  for(int i = 1; i <= n; ++i){
    dp[cur][i] = -m;
  }

  dp[cur][0] = 0;
  for(int j = 1; j <= m; ++j){
    int nxt = 1 ^ cur;
    for(int i = 0; i <= n; ++i){
      dp[nxt][i] = dp[cur][i];
    }

    for(int i = 0; i < n; ++i){
      int k = transition[t[j - 1] - 'a'][i];
      dp[nxt][k] = max(dp[nxt][k], 1 + dp[cur][i]);
    }

    swap(cur, nxt);
  }

  return m - *max_element(dp[cur], dp[cur] + n);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}