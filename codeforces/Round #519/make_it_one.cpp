#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define B 6
#define M (1 << B)

int smallestPrimeDivisor[N], reduced[N], c[N], d[B], s[M], dp[M];
bool visited[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    reduced[i] = i;
    smallestPrimeDivisor[i] = 0;
  }

  for(int i = 2; i < N; ++i){
    for(int j = i; j < N; j += i){
      if(smallestPrimeDivisor[j] == 0){
        smallestPrimeDivisor[j] = i;
      }
      if(reduced[j] % i != 0){
        continue;
      }
      while(reduced[j] % i == 0){
        reduced[j] /= i;
      }
      reduced[j] *= i;
    }
  }
}

int Calculate(int m){
  for(int mask = 0; mask < (1 << m); ++mask){
    int x = 1;
    for(int i = 0; i < m; ++i){
      if((mask & (1 << i)) > 0){
        x *= d[i];
      }
    }
    s[mask] = c[x];
  }

  for(int i = (1 << m) - 1; i > -1; --i){
    for(int j = i + 1; j < (1 << m); ++j){
      if((i & j) == i){
        s[i] -= s[j];
      }
    }
    dp[i] = INT_MAX;
  }

  dp[(1 << m) - 1] = 1;

  for(int i = (1 << m) - 1; i > -1; --i){
    if(dp[i] == INT_MAX){
      continue;
    }
    for(int j = 0; j < i; ++j){
      if(s[j] == 0){
        continue;
      }
      int k = (i & j);
      dp[k] = min(dp[k], 1 + dp[i]);
    }
  }

  return dp[0];
}

int main(){
  int n;
  Initialise();

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    x = reduced[x];
    c[x] = 1;
    visited[x] = 1;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      c[i] += c[j];
    }
  }

  int ans = INT_MAX;
  for(int i = 1; i < N; ++i){
    if(visited[i] == 0){
      continue;
    }

    int m = 0;
    for(int x = i; x > 1; ){
      int k = smallestPrimeDivisor[x];
      d[m++] = k;
      while(x % k == 0){
        x /= k;
      }
    }

    ans = min(ans, Calculate(m));
  }

  if(ans == INT_MAX){
    ans = -1;
  }

  printf("%d\n", ans);

  return 0;
}
