#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int a[N], t[N];
ll A1[N], A2[N], S1[N], S2[N], V1[N], V2[N];

double Solve(ll A1[], ll A2[], ll S1[], ll S2[], ll V1[], ll V2[]){
  double ans = 0;

  for(int i = 1, j = 1; i < N && j < N; ++i){
    if(A1[i] == 0)
      continue;

    for( ; j < N && (A2[j] == 0 || S2[j] < S1[i]); ++j);

    if(j == N || A2[j] == 0)
      continue;

    double ansx = 0;
    if(S1[i] == S2[j])
      ansx = V1[i] + V2[j];
    else
      ansx = V1[i] + (j > 0 ? V2[j - 1] + 1.0 * (S1[i] - S2[j - 1]) / j : 0);

    ans = max(ans, ansx);
  }

  return ans;
}

int main(){
  int n, T;

  scanf("%d%d", &n, &T);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &t[i]);

  double ans = 0;
  for(int i = 1; i <= n; ++i){
    int j = t[i] - T;
    if(j == 0)
      ans += a[i];
    else{
      if(j < 0)
        A1[-j] += a[i];
      else
        A2[j] += a[i];
    }
  }

  for(int i = 1; i < N; ++i){
    V1[i] = (A1[i] + V1[i - 1]);
    S1[i] = (A1[i] * i + S1[i - 1]);
    V2[i] = (A2[i] + V2[i - 1]);
    S2[i] = (A2[i] * i + S2[i - 1]);
  }

  ans += max(Solve(A1, A2, S1, S2, V1, V2), Solve(A2, A1, S2, S1, V2, V1));

  printf("%.15lf\n", ans);

  return 0;
}
