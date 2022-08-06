#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

vector<vector<int>> adj(N);

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

pll DFS(int i, int p){
  ll sum = 0, len = 0, cnt = 0;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    pll ansj = DFS(j, i);
    sum += ansj.first, len += ansj.second, ++cnt;
  }
  len += (1 + cnt);
  sum += len;
  return {sum, len};
}

ll Solve(){
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

  return DFS(1, 0).first;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}