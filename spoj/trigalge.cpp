#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX_ITER 100

const double PI = 4 * atan(1);

int Sgn(double A, double B, double C, double x){
  double y = A * x + B * sin(x) - C;
  if(y == 0){
    return 0;
  }
  return y > 0 ? 1 : -1;
}

double Solve(){
  double A, B, C;
  scanf("%lf%lf%lf", &A, &B, &C);

  double x = ((C - B) / A);
  x = ((int)(x / (2 * PI) - 1)) * 2 * PI;

  for( ; Sgn(A, B, C, x) != 0 && Sgn(A, B, C, x) == Sgn(A, B, C, x + PI / 2); x += PI / 2);

  double y = x + PI / 2;
  for(int iter = 0; iter < MAX_ITER; ++iter){
    double mid = (x + y) / 2;
    if(Sgn(A, B, C, mid) != Sgn(A, B, C, x)){
      y = mid;
    }
    else{
      x = mid;
    }
  }

  return (x + y) / 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.6lf\n", Solve());
  }
  return 0;
}