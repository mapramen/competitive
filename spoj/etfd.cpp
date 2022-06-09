#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define K 21

vector<vector<int>> V(K);
int phi[N], dp[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    phi[i] = i;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      phi[j] -= phi[i];
    }
  }

  for(int i = 2; i < N; ++i){
    dp[i] = 1 + dp[phi[i]];
  }

  for(int i = 1; i < N; ++i){
    V[dp[i]].push_back(i);
  }
}

int GetCount(int k, int n){
  return upper_bound(V[k].begin(), V[k].end(), n) - V[k].begin();
}

int Solve(){
  int k, l, r;
  scanf("%d%d%d", &l, &r, &k);
  return GetCount(k, r) - GetCount(k, l - 1);
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}