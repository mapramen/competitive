#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

double PI = 4 * atan(1);
ll a[N], INV_EPS = 1E5;

bool Check(int n, int m, ll s){
  ll c = 0;
  for(int i = 1; i <= n; ++i){
    c += a[i] / s;
  }
  return m <= c;
}

ll BinarySearch(int n, int m){
  ll x = 1, y = *max_element(a + 1, a + n + 1), ans = 0;

  while(x <= y){
    ll mid = (x + y) / 2;
    if(Check(n, m, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  return ans;
}

double Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    int r;
    scanf("%d", &r);
    a[i] = INV_EPS * r * r;
  }

  return (PI * BinarySearch(n, m + 1)) / INV_EPS;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.6lf\n", Solve());
  }
  return 0;
}