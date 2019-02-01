#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int n, a[N], b[N], p;
double eps = 1E-6;

bool Check(double t){
  double tx = 0, ty = 0;
  ty = p * t;

  for(int i = 1; i <= n; i++)
    tx += max(0.0, a[i] * t - b[i]);

  return tx <= ty;
}

double BinarySearch(){
  double x = 0, y = 1E14, z = 0;

  while(y - x >= eps / 2){
    double mid = x + (y - x) / 2;

    if(Check(mid)){
      z = mid;
      x = mid + eps;
    }
    else
      y = mid - eps;
  }

  return z;
}

int main(){
  ll s = 0;

  scanf("%d%d", &n, &p);

  for(int i = 1; i <= n; i++){
    scanf("%d%d", &a[i], &b[i]);
    s += a[i];
  }

  if(s <= p)
    printf("-1\n");
  else
    printf("%.9lf\n", BinarySearch());

  return 0;
}
