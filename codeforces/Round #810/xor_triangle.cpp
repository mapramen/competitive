#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define M 8
#define MOD 998244353 

char s[N];
int dp[2][M][M];

void Reset(int dp[M][M]){
  for(int x = 0; x < M; ++x){
    for(int y = 0; y < M; ++y){
      dp[x][y] = 0;
    }
  }
}

int GetMask(int a, int b, int c){
  return a * 4 + b * 2 + c;
}

int GetKthBit(int mask, int k){
  return (mask & (1 << k)) != 0;
}

int main(){
  scanf("%s", s);

  int cur = 0;
  Reset(dp[cur]);
  dp[cur][M - 1][0] = 1;

  for(int i = 0; s[i] != '\0'; ++i){
    int nxt = 1 ^ cur, n = s[i] == '1';
    Reset(dp[nxt]);

    for(int x = 0; x < M; ++x){
      for(int y = 0; y < M; ++y){
        for(int z = 0; z < M; ++z){
          int pa = GetKthBit(x, 0), pb = GetKthBit(x, 1), pc = GetKthBit(x, 2);
          int qa = GetKthBit(y, 0), qb = GetKthBit(y, 1), qc = GetKthBit(y, 2);
          int a = GetKthBit(z, 0), b = GetKthBit(z, 1), c = GetKthBit(z, 2);
          
          if(n == 0 && ((pa == 1 && a == 1) || (pb == 1 && b == 1) || (pc == 1 && c == 1))){
            continue;
          }

          pa &= (1 ^ n ^ a);
          pb &= (1 ^ n ^ b);
          pc &= (1 ^ n ^ c);

          qa |= ((a ^ b) & (a ^ c));
          qb |= ((b ^ a) & (b ^ c));
          qc |= ((c ^ a) & (c ^ b));

          int nx = GetMask(pa, pb, pc), ny = GetMask(qa, qb, qc);
          dp[nxt][nx][ny] = (dp[nxt][nx][ny] + dp[cur][x][y]) % MOD;
        }
      }
    }

    swap(cur, nxt);
  }

  int ans = 0;
  for(int x = 0; x < M; ++x){
    ans = (ans + dp[cur][x][M - 1]) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}