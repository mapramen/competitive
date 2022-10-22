#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 200001

vector<vector<tiii>> adj(N);
int ans[N];
vector<ll> B;

void DFS(int i, ll A){
  ans[i] = upper_bound(B.begin(), B.end(), A) - B.begin() - 1;
  for(auto [j, a, b]: adj[i]){
    B.push_back(B.back() + b);
    DFS(j, A + a);
    B.pop_back();
  }
  adj[i].clear();
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int j = 2; j <= n; ++j){
    int i, a, b;
    scanf("%d%d%d", &i, &a, &b);
    adj[i].push_back({j, a, b});
  }

  B.resize(1);
  DFS(1, 0);

  for(int i = 2; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}