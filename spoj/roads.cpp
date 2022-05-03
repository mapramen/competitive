#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 101
#define M 10001

vector<vector<tiii>> adj(N);
int dp[N][M];
priority_queue<tiii,vector<tiii>,greater<tiii>> Q;

void Reset(int n, int m){
  for(int i = 1; i <= n; ++i){
    for(int c = 0; c <= m; ++c){
      dp[i][c] = INT_MAX;
    }
  }

  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

void CheckAndPush(int m, int i, int c, int val){
  if(c <= m && val < dp[i][c]){
    dp[i][c] = val;
    Q.push({val, i, c});
  }
}

int Solve(){
  int n, m, r;
  scanf("%d%d%d", &m, &n, &r);

  Reset(n, m);

  while(r--){
    int i, j, w, c;
    scanf("%d%d%d%d", &i, &j, &w, &c);
    adj[i].push_back({j, w, c});
  }

  CheckAndPush(m, 1, 0, 0);

  while(!Q.empty()){
    tiii t = Q.top();
    Q.pop();

    int dpic = get<0>(t), i = get<1>(t), c = get<2>(t);
    if(dp[i][c] != dpic){
      continue;
    }

    for(tiii edge: adj[i]){
      int j = get<0>(edge), w = get<1>(edge), cij = get<2>(edge);
      CheckAndPush(m, j, c + cij, dpic + w);
    }
  }

  int ans = *min_element(dp[n], dp[n] + m + 1);
  return ans == INT_MAX ? -1 : ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}