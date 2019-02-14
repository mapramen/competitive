#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

vector< vector<int> > adj(N);
vector< pii > v;
int w[N], b[N], maxw, sumw, sumb, dp[N], inf = 2E9;
bool visited[N];

void DFS(int i){
  visited[i] = 1;
  sumw += w[i];
  sumb += b[i];
  v.PB(MP(w[i], b[i]));

  for(int j = 0; j < adj[i].size(); j++){
    int k = adj[i][j];

    if(visited[k] == 0)
      DFS(k);
  }
}

void KnapSack(){
  for(int i = maxw; i >= 0; i--){
    for(int j = 0; j < v.size(); j++){
      int x = v[j].first, y = v[j].second;
      if(x <= i)
        dp[i] = max(dp[i], dp[i - x] + y);
    }
  }
}

int main(){
  int n, m, i, j, k, ans = 0;

  scanf("%d%d%d", &n, &m, &maxw);

  for(i = 1; i <= n; i++)
    scanf("%d", &w[i]);

  for(i = 1; i <= n; i++)
    scanf("%d", &b[i]);

  for(i = 1; i <= maxw; i++)
    dp[i] = -inf;

  while(m--){
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(i = 1; i <= n; i++){
    if(visited[i] == 1)
      continue;

    sumw = sumb = 0;
    v.clear();
    DFS(i);
    v.PB(MP(sumw, sumb));

    KnapSack();
  }

  for(i = 1; i <= maxw; i++)
    ans = max(ans, dp[i]);

  printf("%d\n", ans);

  return 0;
}
