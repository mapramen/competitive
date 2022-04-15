#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 20000
#define LOGN 16

int a[3 * N], lg[3 * N], T[LOGN][3 * N];

void PreProcess(int n){
  for(int i = 2; i <= 3 * n; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }

  for(int i = n; i < 3 * n; ++i){
    a[i] = a[i - n];
  }

  for(int i = 0; i < 3 * n; ++i){
    T[0][i] = a[i];
  }

  for(int k = 1; k < LOGN; ++k){
    for(int i = 0, j = (1 << (k - 1)); j < 3 * n; ++i, ++j){
      T[k][i] = T[k - 1][i] & T[k - 1][j];
    }
  }
}

int Query(int i, int j){
  int k = lg[j - i + 1];
  return T[k][i] & T[k][j - (1 << k) + 1];
}

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);

  k = min(k + 1, n);
  for(int i = n; i < 2 * n; ++i){
    printf("%d ", Query(i - k + 1, i + k - 1));
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