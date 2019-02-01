#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll b[2][3], m[2][3], a[3], v[3];

double Dist2(double t){
  double ans = 0;
  for(int i = 0; i < 3; ++i){
    double ansx = a[i] + v[i] * t;
    ans += ansx * ansx;
  }
  return ans;
}

int main(){
  ll T;
  double ans;

  cin >> T;

  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 3; ++j)
      cin >> b[i][j];
    for(int j = 0; j < 3; ++j)
      cin >> m[i][j];
  }

  for(int j = 0; j < 3; ++j){
    a[j] = b[0][j] - b[1][j];
    v[j] = m[0][j] - m[1][j];
  }

  ans = min(Dist2(0.0), Dist2((double)T));

  ll p = 0, q = 0;
  for(int j = 0; j < 3; ++j){
    p += a[j] * v[j];
    q += v[j] * v[j];
  }

  if(p + q * T >= 0 && p <= 0){
    double t = -p;
    t /= q;
    ans = min(ans, Dist2(t));
  }

  ans = sqrt(ans);

  printf("%.15lf\n", ans);

  return 0;
}
