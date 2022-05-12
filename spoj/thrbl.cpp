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
      T[k][i] = max(T[k - 1][i], T[k - 1][j]);
    }
  }
}

int RMQ(int i, int j){
  int k = lg[j - i + 1];
  return max(T[k][i], T[k][j - (1 << k) + 1]);
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &T[0][i]);
  }

  PreProcess(n);

  int ans = 0;
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    ans += RMQ(l, r - 1) == RMQ(l, l);
  }

  printf("%d\n", ans);
  
  return 0;
}