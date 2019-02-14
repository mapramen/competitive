#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define PB push_back
#define MP make_pair
#define N 100001

int n;
pdd p[N];
double mx, my, sn, cs, r[N], rMin;

double Hypotenuse(double a, double b){
  return sqrt(a * a + b * b);
}

double RightAngleSide(double c, double a){
  return sqrt(max(0.0, c * c - a * a));
}

double Dist(pdd a, pdd b){
  double x = a.first - b.first;
  double y = a.second - b.second;
  return Hypotenuse(x, y);
}

void PreProcess(){
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  mx = x1 + x2;
  my = y1 + y2;
  mx /= 2;
  my /= 2;

  int a = - (x2 - x1), b = (y2 - y1), g = __gcd(abs(a), abs(b));

  rMin = Hypotenuse(1.0 * a, 1.0 * b) / 2;

  a /= g, b /= g;
  double c = Hypotenuse(1.0 * a, 1.0 * b);
  sn = a / c, cs = b / c;

  printf("mx = %lf my = %lf\n", mx, my);
  printf("sin = %lf cos = %lf\n", sn, cs);
  printf("rMin = %lf\n", rMin);
}

bool CheckCircle(pdd c, double R){
  printf("CheckCircle: %lf %lf %lf\n", c.first, c.second, R);
  for(int i = 1; i <= n; ++i){
    double d = Dist(c, p[i]);
    printf("%d %lf %lf\n", i, r[i], d);
    if(d <= R - r[i] || d >= R + r[i])
      continue;
    else
      return 0;
  }
  return 1;
}

bool Check(double R){
  double l = RightAngleSide(R, rMin);
  pdd c1 = MP(mx + l * cs, my + l * sn), c2 = MP(mx - l * cs, my - l * sn);
  return (CheckCircle(c1, R) | CheckCircle(c2, R));
}

double BinarySearch(){
  int iter = 200;
  double x = rMin, y = 1E12;
  while(iter--){
    double R = (x + y) / 2;
    printf("x = %lf y = %lf R = %lf\n", x, y, R);
    if(Check(R))
      y = R;
    else
      x = R;
  }
  return (x + y) / 2;
}

int main(){
  PreProcess();

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i)
    scanf("%lf%lf%lf", &p[i].first, &p[i].second, &r[i]);

  printf("%.15lf\n", BinarySearch());

  return 0;
}
