#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 3001
#define P 1000003
#define MOD 1000000007

vector<vector<int>> adj(N);
map<int,int> dp;

void Reset(int n){
  dp[INT_MAX] = 0;
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

int GetIsoNumber(vector<int>& v){
  sort(v.begin(), v.end());

  int hsh = 0;
  for(int x: v){
    hsh = (1ll * hsh * P + x) % MOD;
  }

  auto it = dp.find(hsh);
  if(it != dp.end()){
    return it->second;
  }

  int ans = dp.size();
  dp[hsh] = ans;
  return ans;
}

int DFS(int i, int p){
  vector<int> v;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    v.push_back(DFS(j, i));
  }
  return GetIsoNumber(v);
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);
  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  set<int> S;
  for(int i = 1; i <= n; ++i){
    if(adj[i].size() < 2){
      S.insert(DFS(i, 0));
    }
  }

  return S.size();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}