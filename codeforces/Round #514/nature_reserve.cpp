#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define MAX_ITER 100

int x[N], y[N];

bool ValidateInputs(int n){
  int m = 0;

  for(int i = 1; i <= n; ++i){
    m += (y[i] > 0);
  }

  if(min(m, n - m) > 0){
    return 0;
  }

  if(m == 0){
    for(int i = 1; i <= n; ++i){
      y[i] = -y[i];
    }
  }

  return 1;
}

bool Check(int n, double r){
  double x1 = LLONG_MIN, x2 = LLONG_MAX;
  for(int i = 1; i <= n; ++i){
    double s = 2 * y[i] * r - 1ll * y[i] * y[i];
    if(s < 0){
      return 0;
    }
    s = sqrt(s);
    x1 = max(x1, x[i] - s);
    x2 = min(x2, x[i] + s);
  }
  return (x1 <= x2);
}

double BinarySearch(int n){
  double x = 0, y = 1E20, ans = -100;
  for(int iter = 0; iter <= MAX_ITER; ++iter){
    double mid = x + (y - x) / 2;
    if(Check(n, mid)){
      ans = mid;
      y = mid;
    }
    else{
      x = mid;
    }
  }
  return ans;
}


int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &x[i], &y[i]);
  }

  if(!ValidateInputs(n)){
    printf("-1\n");
  }
  else{
    printf("%.15lf\n", BinarySearch(n));
  }

  return 0;
}
