#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001
#define MOD 998244353 

char s[N];
int c[N][N];

int main(){
  int n, k;
  scanf("%d%d%s", &n, &k, s);

  for(int i = 0; i <= n; ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD; 
    }
  }

  int ones = 0;
  for(int i = 0; i < n; ++i){
    ones += (s[i] == '1');
  }

  int ans = 1;
  for(int i = 0; i < n && ones >= k; ++i){
    int c0 = 0, c1 = 0;
    for(int j = i; j < n; ++j){
      c0 += (s[j] == '0');
      c1 += (s[j] == '1');

      if(c1 > k){
        continue;
      }

      int c0x = c0, c1x = c1;
      
      if(s[i] == '0'){
        --c1x;
      }
      else{
        --c0x;
      }

      if(s[j] == '0'){
        --c1x;
      }
      else{
        --c0x;
      }

      if(c0x < 0 || c1x < 0){
        continue;
      }

      ans = (ans + c[c0x + c1x][c0x]) % MOD;
    }
  }

  printf("%d\n", ans);

  return 0;
}