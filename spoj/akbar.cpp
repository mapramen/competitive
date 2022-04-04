#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

vector<vector<int>> adj(N);
int marker[N];
queue<pii> Q;

bool Check(int k, int i, int d){
  while(!Q.empty()){
    Q.pop();
  }

  Q.push({i, d});
  while(!Q.empty()){
    tie(i, d) = Q.front();
    Q.pop();

    if(d < 0){
      continue;
    }

    if(marker[i] != 0){
      if(marker[i] == k){
        continue;
      }
      return false;
    }

    marker[i] = k;
    for(int j: adj[i]){
      Q.push({j, d - 1});
    }
  }

  return true;
}

bool Solve(){
  int n, r, m;
  scanf("%d%d%d", &n, &r, &m);

  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    marker[i] = 0;
  }

  while(r--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  bool ans = true;
  for(int k = 1; k <= m; ++k){
    int i, d;
    scanf("%d%d", &i, &d);
    ans = ans && Check(k, i, d);
  }

  for(int i = 1; i <= n; ++i){
    ans = ans && marker[i] != 0;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Yes" : "No");
  }
  return 0;
}