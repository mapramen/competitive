#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define LOGN 20

int a[N], lg[N], T[LOGN][N];
int ans[N];

void PreProcess(int n){
  for(int i = 2; i <= n; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }

  for(int k = 1; k < LOGN; ++k){
    for(int i = 1, j = 1 + (1 << (k - 1)); j <= n; ++i, ++j){
      T[k][i] = __gcd(T[k - 1][i], T[k - 1][j]);
    }
  }
}

int Query(int l, int r){
  int k = lg[(r - l + 1)];
  return __gcd(T[k][l], T[k][(r - (1 << k) + 1)]);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &T[0][i]);
  }

  PreProcess(n);

  for(int i = 1, j = 1, c = 0; j <= n; ans[j] = c, ++j){
    while(i < j && Query(i, j) < j - i + 1){
      ++i;
    }

    if(Query(i, j) == j - i + 1){
      ++c;
      i = j + 1;
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}