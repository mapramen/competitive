#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define LOGN 16

int lg[N], T[LOGN + 1][N];

void PreProcess(int n){
  for(int i = 2; i <= n; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }

  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1, j = 1 + (1 << (k - 1)); j <= n; ++i, ++j){
      T[k][i] = min(T[k - 1][i], T[k - 1][j]);
    }
  }
}

int RMQ(int i, int j){
  int k = lg[j - i + 1];
  return min(T[k][i], T[k][j - (1 << k) + 1]);
}

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &T[0][i]);
  }

  PreProcess(n);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", RMQ(l, r));
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Scenario #%d:\n", k);
    Solve();
  }
  return 0;
}