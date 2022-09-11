#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);
int L[N], R[N], C[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int i = 2; i <= n; ++i){
    int p;
    scanf("%d", &p);
    adj[p].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &L[i], &R[i]);
  }

  int ans = 0;
  for(int i = n; i != 0; --i){
    int x = 0;
    for(int j: adj[i]){
      x = min(R[i], x + C[j]);
    }
    if(x < L[i]){
      C[i] = R[i];
      ++ans;
    }
    else{
      C[i] = x;
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}