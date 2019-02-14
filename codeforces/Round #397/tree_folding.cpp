#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
set<int> dp[N], dp1[N], dp2[N];
bool isBadUp[N], isBadDown[N];

void DFS1(int i, int p){
  for(auto k : adj[i]){
    if(k == p)
      continue;

    DFS1(k, i);

    if(isBadDown[i] == 0 && isBadDown[k] == 0 && dp1[k].size() < 2){
      for(auto x : dp1[k])
        dp1[i].insert(1 + x);
    }

    isBadDown[i] |= (isBadDown[k] || dp1[k].size() > 1);
  }

  if(dp1[i].size() == 0)
    dp1[i].insert(0);

  if(isBadDown[i])
    dp1[i].clear();
}

void DFS2(int i, int p){
  int badCount = 0;
  map<int,int> c;

  isBadUp[i] |= (dp2[i].size() > 1);

  if(isBadUp[i] == 0){
    if(adj[i].size() == 1)
      c[1] = 1;

    for(auto x : dp2[i])
      c[x + 1]++;

    for(auto k : adj[i]){
      if(k != p){
        if(isBadDown[k])
          badCount++;
        else{
          for(auto x : dp1[k])
            c[x + 2]++;
        }
      }
    }
  }

  if(isBadUp[i] == 1|| c.size() > 3){
    for(auto k : adj[i]){
      if(k != p){
        isBadUp[k] = 1;
        DFS2(k, i);
      }
    }
  }
  else{
    for(auto k : adj[i]){
      if(k == p)
        continue;

      if(badCount == 0 || (badCount == 1 && isBadDown[k] == 1)){
        for(auto it : c){
          if(dp1[k].size() == 0 || dp1[k].find(it.first - 2) == dp1[k].end() || it.second > 1)
            dp2[k].insert(it.first);
        }
      }
      else
        isBadUp[k] = 1;

      DFS2(k, i);
    }
  }
}

int main(){
  int n, ans = INT_MAX;

  scanf("%d", &n);

  for(int k = 1; k < n; k++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS1(1, 0);
  DFS2(1, 0);

  for(int i = 1; i <= n; i++){
    if(isBadUp[i] || isBadDown[i])
      continue;

    for(auto x : dp1[i])
      dp[i].insert(x);

    for(auto x : dp2[i])
      dp[i].insert(x);

    if(dp[i].size() <= 2){
      int ansx = 0;

      for(auto x : dp[i])
        ansx += x;

      ans = min(ans, ansx);
    }
  }

  while(ans % 2 == 0)
    ans /= 2;

  if(ans == INT_MAX)
    ans = -1;

  printf("%d\n", ans);

  return 0;
}
