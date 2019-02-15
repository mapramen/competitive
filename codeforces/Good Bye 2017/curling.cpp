#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

double y[N];

int main(){
  int n, r;

  cin >> n >> r;

  while(n--){
    int x;
    double ans = r;

    cin >> x;
    for(int i = 1; i < N; ++i){
      if(abs(x - i) > 2 * r || y[i] < r)
        continue;
      int a = abs(x - i);
      double ansx = y[i] + sqrt(4 * r * r - a * a);
      ans = max(ans, ansx);
    }

    printf("%.9lf ", ans);
    y[x] = ans;
  }
  printf("\n");

  return 0;
}
