#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N), c(N);
int dp1[N], dp2[N], groupNo[N], groupSize[N], diameter[N], totalGroups = 0;

void DFS1(int i, int p){
  groupNo[i] = totalGroups;
  groupSize[groupNo[i]]++;
  for(auto k : adj[i]){
    if(k == p)
      continue;
    DFS1(k, i);
    dp1[i] = max(dp1[i], 1 + dp1[k]);
  }
}

void DFS2(int i, int p){
  int max1 = 1 + dp2[i], max2 = 1 + dp2[i];

  for(auto k : adj[i]){
    if(k == p)
      continue;
    int x = 2 + dp1[k];
    if(x >= max1)
      tie(max1, max2) = MP(x, max1);
    else if(x > max2)
      max2 = x;
    else;
  }

  for(auto k : adj[i]){
    if(k == p)
      continue;
    int x = 2 + dp1[k];
    if(x == max1)
      dp2[k] = max2;
    else
      dp2[k] = max1;
    DFS2(k, i);
  }
}

double Query(int u, int v){
  int d = diameter[v], n1 = groupSize[u], n2 = groupSize[v];
  double ans = 0;
  ll S = 0, C = 0;
  for(int i = 0, j = c[v].size() - 1; i < c[u].size(); i++){
    for( ; j > -1 && i + j + 1 > d; j--){
      S += 1ll * c[v][j] * j;
      C += c[v][j];
    }
    ans += (c[u][i] * S + c[u][i] * C * (1 + i) + c[u][i] * (n2 - C) * d);
  }
  ans /= (1ll * n1 * n2);
  return ans;
}

int main(){
  int n, m, q;

  scanf("%d%d%d", &n, &m, &q);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(int i = 1; i <= n; i++){
    if(groupNo[i] == 0){
      ++totalGroups;
      DFS1(i, 0);
      DFS2(i, 0);
    }
  }

  for(int i = 1; i <= n; i++){
    int g = groupNo[i], d = max(dp1[i], dp2[i]);
    diameter[g] = max(diameter[g], d);
  }

  for(int g = 1; g <= totalGroups; g++)
    c[g].resize(diameter[g] + 1);

  for(int i = 1; i <= n; i++){
    int g = groupNo[i], d = max(dp1[i], dp2[i]);
    c[g][d]++;
  }

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    i = groupNo[i], j = groupNo[j];
    if(i == j)
      printf("-1\n");
    else{
      if(c[i].size() > c[j].size())
        swap(i, j);
      printf("%.15lf\n", Query(i, j));
    }
  }

  return 0;
}
