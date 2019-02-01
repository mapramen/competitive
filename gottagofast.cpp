#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 52
#define M 5001

int n, m, f[N], s[N];
double p[N], dp[N][M];

double Compute(double mid){
  for(int i = 1; i <= n; ++i)
    for(int j = 0; j <= m; ++j)
      dp[i][j] = mid;

  for(int i = n; i > 0; --i){
    for(int j = 0; j <= m; ++j){
      if(j + f[i] <= m){
        double val = p[i] * (f[i] + dp[i + 1][j + f[i]]);
        if(j + s[i] <= m)
          val += (1 - p[i]) * (s[i] + dp[i + 1][j + s[i]]);
        else
          val += (1 - p[i]) * (s[i] + mid);
        dp[i][j] = min(dp[i][j], val);
      }
    }
  }

  return dp[1][0];
}

double BinarySearch(){
  int iter = 200;
  double x = 0, y = 1E20, z = y;
  while(iter--){
    double mid = (x + y) / 2;
    double ans = Compute(mid);
    if(ans == mid)
      x = mid;
    else
      y = mid;
  }
  return (x + y) / 2;
}

int main(){
  cin >> n >> m;

  for(int i = 1; i <= n; ++i)
    cin >> f[i] >> s[i] >> p[i];

  for(int i = 1; i <= n; ++i)
    p[i] /= 100;

  printf("%.15lf\n", BinarySearch());

  return 0;
}
