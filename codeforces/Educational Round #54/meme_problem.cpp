#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;

  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n > 0 && n < 4){
      printf("N\n");
    }
    else{
      double s = n * n;
      s -= 4 * n;
      s = sqrt(s);
      double a = (n - s) / 2, b = n - a;
      printf("Y %.15lf %.15lf\n", a, b);
    }
  }

  return 0;
}
