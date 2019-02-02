#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m, s;
  double ans = 0, ansx = 1;

  cin >> n >> m;
  s = n * m;

  for(int k = 1; k <= min(n, m); ++k){
    ansx *= (n - k + 1);
    ansx /= (s - k + 1);
    ans += (k * ansx / n);
  }

  printf("%.15lf\n", ans);

  return 0;
}
