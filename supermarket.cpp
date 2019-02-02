#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m;
  double ans = 10000;

  cin >> n >> m;

  while(n--){
    double a, b;
    cin >> a >> b;
    ans = min(ans, (a * m) / b);
  }

  printf("%.15lf\n", ans);

  return 0;
}
