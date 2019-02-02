#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int dp[N][2];

int main(){
  int n;

  for(int x = 0; x < 2; x++)
    dp[0][x] = INT_MIN / 2;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int a;
    scanf("%d", &a);
    int x = (a % 2 != 0);

    for(int y = 0; y < 2; y++){
      int k = (x + y) % 2;
      dp[i][k] = max(dp[i - 1][k], dp[i - 1][y] + a);
    }

    dp[i][x] = max(dp[i][x], a);
  }

  printf("%d\n", dp[n][1]);
  return 0;
}
