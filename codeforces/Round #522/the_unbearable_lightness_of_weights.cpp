#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101
#define M 10001

int dp[M][N];

int main(){
  int n;
  set<int> S;

  cin >> n;
  for(int x = 1; x <= n; ++x){
    int a;
    cin >> a;
    S.insert(a);

    for(int i = M - 1; i > a; --i){
      for(int j = 1; j <= n; ++j){
        if(dp[i - a][j - 1]){
          dp[i][j] = max(dp[i][j], max(a, dp[i - a][j - 1]));
        }
      }
    }

    dp[a][1] = a;
  }

  int ans = 0;
  for(int i = 1; i < M; ++i){
    for(int j = 1; j <= n; ++j){
      if(i % j == 0 && i / j == dp[i][j]){
        ans = max(ans, j);
      }
    }
  }

  if(S.size() < 3){
    ans = n;
  }

  printf("%d\n", ans);

  return 0;
}
