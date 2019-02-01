#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101
#define M 11

double dp[M * N][N], inf = 1E18, F = 0.9;

bool CheckQuadraticRootInRange(double A, double B, double C, double x1, double x2){
  double D = B * B - 4 * A * C;

  if(D < 0){
    return 0;
  }

  D = sqrt(D);
  x1 = B + 2 * A * x1, x2 = B + 2 * A * x2;

  return (x1 <= -D && -D <= x2) || (x1 <= D && D <= x2);
}

bool Check(double C, double T, int n, double a){
  return CheckQuadraticRootInRange(C, (10 * n - T) * C + 1, 10 * n - T + a, 0.0, T);
}

int Solve(){
  int n;
  double C, T;
  vector< pii > A;

  cin >> n >> C >> T;

  for(int i = 1; i <= n; ++i){
    int a, p;
    cin >> a >> p;
    A.PB(MP(a, p));
  }

  for(int i = 0; i < N * M; ++i){
    for(int j = 0; j < N; ++j){
      dp[i][j] = inf;
    }
  }

  sort(A.begin(), A.end(), greater< pii >());

  dp[0][0] = 0;
  for(int x = 0; x < n; ++x){
    int a, p;
    tie(a, p) = A[x];
    for(int i = (M - 1) * (x + 1); i >= p; --i){
      double f = a / F;
      for(int j = 1; j <= (x + 1); ++j, f /= F){
        dp[i][j] = min(dp[i][j], dp[i - p][j - 1] + f);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < N * M; ++i){
    for(int j = 0; j < N; ++j){
      if(dp[i][j] == inf || !Check(C, T, j, dp[i][j])){
        continue;
      }
      ans = i;
    }
  }

  return ans;
}

int main(){
  int t;

  cin >> t;
  while(t--){
    cout << Solve() << '\n';
  }

  return 0;
}
