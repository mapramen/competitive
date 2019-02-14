#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001
#define M 5000
#define B 4

int a[N], d[M];
ll dp[B][B * M];

int main(){
  int n;
  double p, q;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++)
      d[abs(a[i] - a[j])]++;

  dp[0][2 * M] = 1;

  for(int i = 1; i < 3; i++)
    for(int j = 0; j < B * M; j++)
      for(int x = 1; x < M; x++)
        if(j - x >= 0)
          dp[i][j - x] += d[x] * dp[i - 1][j];

  for(int i = 3, j = 0; j < B * M; j++)
    for(int x = 1; x < M; x++)
      if(j + x < B * M)
        dp[i][j + x] += d[x] * dp[i - 1][j];

  q = 0;
  for(int j = 0; j < B * M; j++)
    q += dp[3][j];

  p = 0;
  for(int j = 2 * M + 1; j < B * M; j++)
    p += dp[3][j];

  printf("%.10lf\n", p / q);

  return 0;
}
