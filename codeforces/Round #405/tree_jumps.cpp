#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define B 5

vector< vector<int> > adj(N);
int K;
ll dp1[N], dp2[N], cnt1[N][B], cnt2[N][B], ans;

void DFS1(int i, int p){
  for(auto k : adj[i]){
    if(k == p)
      continue;

    DFS1(k, i);
    dp1[i] += dp1[k];
    for(int x = 0; x < K; x++)
      cnt1[i][(x + 1) % K] += cnt1[k][x];
  }
  dp1[i] += cnt1[i][1 % K];
  cnt1[i][0]++;
  ans += dp1[i];
}

void DFS2(int i, int p){
  ans += dp2[i];
  for(auto k : adj[i]){
    if(k == p)
      continue;

    dp2[k] = dp2[i] + dp1[i] - dp1[k] - cnt1[k][0];

    for(int x = 0; x < K; x++){
      cnt2[k][(x + 1) % K] += (cnt2[i][x] + cnt1[i][x]);
      cnt2[k][(x + 2) % K] -= cnt1[k][x];
    }

    dp2[k] += cnt2[k][1 % K];
    DFS2(k, i);
  }
}

int main(){
  int n;

  scanf("%d%d", &n, &K);

  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS1(1, 0);
  DFS2(1, 0);

  printf("%lld\n", ans / 2);

  return 0;
}
