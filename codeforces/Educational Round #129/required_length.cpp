#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

const int INF = 1E9;
map<__int128,int> dp;

__int128 Read(){
  __int128 x = 0;
  getchar();
  while(true){
    char c = getchar();
    if(!isdigit(c)){
      break;
    }
    x = 10 * x + (c - '0');
  }
  return x;
}

int GetLength(__int128 x){
  int ans = 0;
  for( ; x != 0; x /= 10){
    ++ans;
  }
  return ans;
}

int DP(int n, __int128 m, __int128 x){
  if(x > m){
    return INF;
  }

  auto it = dp.find(x);
  if(it != dp.end()){
    return it->second;
  }

  if(GetLength(x) == n){
    dp[x] = 0;
    return 0;
  }

  int ans = INF;
  for(__int128 y = x; y != 0; y /= 10){
    int d = y % 10;
    if(d > 1){
      ans = min(ans, 1 + DP(n, m, d * x));
    }
  }

  dp[x] = ans;
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  __int128 x = Read();

  __int128 m = 0;
  for(int i = 1; i <= n; ++i){
    m = 10 * m + 9;
  }

  int ans = DP(n, m, x);
  if(ans == INF){
    ans = -1;
  }

  printf("%d\n", ans);

  return 0;
}