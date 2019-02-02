#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int a[N];
ll sum[N], dp[N], ans = LLONG_MIN;
bool visited[N];

void DFS(int i){
  visited[i] = 1;
  pll ansx = MP(LLONG_MIN, LLONG_MIN);
  sum[i] = a[i];
  dp[i] = LLONG_MIN;

  for(auto k : adj[i]){
    if(visited[k] == 0){
      DFS(k);
      sum[i] += sum[k];
      dp[i] = max(dp[i], dp[k]);
      ansx = max(ansx, MP(ansx.first, dp[k]));
      if(ansx.first < ansx.second)
        swap(ansx.first, ansx.second);
    }
  }

  if(ansx.second != LLONG_MIN)
    ans = max(ans, ansx.first + ansx.second);

  dp[i] = max(dp[i], sum[i]);
}

int main(){
  int n, m, i, j, k;

  scanf("%d", &n);

  for(i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(k = 1; k < n; k++){
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1);

  if(ans == LLONG_MIN)
    cout << "Impossible\n";
  else
    cout << ans << '\n';

  return 0;
}
