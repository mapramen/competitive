#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51

char s[2 * N];
ull dpMin[N][N], dpMax[N][N];

void Solve(){
  scanf("%s", s);

  int n = (strlen(s) + 1) / 2;
  
  for(int i = 1; i <= n; ++i){
    dpMin[i][i] = dpMax[i][i] = s[2 * i - 2] - '0';
  }

  for(int len = 2; len <= n; ++len){
    for(int i = 1, j = len; j <= n; ++i, ++j){
      ull ansMin = ULLONG_MAX, ansMax = 0;
      for(int k = i; k < j; ++k){
        if(s[2 * k - 1] == '+'){
          ansMin = min(ansMin, dpMin[i][k] + dpMin[k + 1][j]);
          ansMax = max(ansMax, dpMax[i][k] + dpMax[k + 1][j]);

        }
        else{
          ansMin = min(ansMin, dpMin[i][k] * dpMin[k + 1][j]);
          ansMax = max(ansMax, dpMax[i][k] * dpMax[k + 1][j]);
        }
      }
      dpMin[i][j] = ansMin, dpMax[i][j] = ansMax;
    }
  }

  printf("%llu %llu\n", dpMax[1][n], dpMin[1][n]);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}