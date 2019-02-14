#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define B 26

vector< vector<int> > adj(N);
int a[N][B], inDegree[N], dp[N][B];
char s[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  scanf("%s", s);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    ++inDegree[j];
  }

  for(int i = 1; i <= n; ++i){
    int j = s[i - 1] - 'a';
    ++a[i][j];
    ++dp[i][j];
  }

  queue<int> Q;
  for(int i = 1; i <= n; ++i){
    if(inDegree[i] == 0)
      Q.push(i);
  }

  int nLeft = n, ans = 0;
  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    --nLeft;

    for(int j = 0; j < B; ++j)
      ans = max(ans, dp[i][j]);

    for(auto k : adj[i]){
      for(int j = 0; j < B; ++j)
        dp[k][j] = max(dp[k][j], dp[i][j] + a[k][j]);

      --inDegree[k];
      if(inDegree[k] == 0)
        Q.push(k);
    }
  }

  if(nLeft)
    ans = -1;

  printf("%d\n", ans);

  return 0;
}
