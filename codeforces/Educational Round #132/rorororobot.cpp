#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define LOGN 18

int lg[N], T[LOGN][N];

void PreProcess(int n){
  for(int i = 2; i <= n; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }

  for(int k = 1; k <= lg[n]; ++k){
    for(int i = 1, j = 1 + (1 << (k - 1)); j <= n; ++i, ++j){
      T[k][i] = max(T[k - 1][i], T[k - 1][j]);
    }
  }
}

int Query(int i, int j){
  if(i > j){
    swap(i, j);
  }
  int k = lg[(j - i + 1)];
  j -= ((1 << k) - 1);
  return max(T[k][i], T[k][j]);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= m; ++i){
    scanf("%d", &T[0][i]);
  }

  PreProcess(m);

  int q;
  scanf("%d", &q);

  while(q--){
    int x1, y1, x2, y2, k;
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
    int z = ((n - x1) / k) * k + x1;
    printf("%s\n", (x1 % k == x2 % k) && (y1 % k == y2 % k) && Query(y1, y2) < z ? "YES" : "NO");
  }

  return 0;
}