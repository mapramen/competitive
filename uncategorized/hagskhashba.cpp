#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair< double, double >
#define PB push_back
#define MP make_pair
#define N 10001

pdd p[N];
double d[N];

double dist2(pdd a, pdd b){
  double x = a.first - b.first;
  double y = a.second - b.second;
  return x * x + y * y;
}

double dist(pdd a, pdd b){
  return sqrt(dist2(a, b));
}

int CrossProductSign(pdd a, pdd b){
  double ans = a.first * b.second - a.second * b.first;
  if(ans == 0)
    return 0;
  else
    if(ans < 0)
      return -1;
    else
      return 1;
}

vector< pdd > TargetPoints(pdd a, pdd b, double r1, double r2){
  double x1 = a.first, y1 = a.second;
  double x2 = b.first, y2 = b.second;

  r1 *= r1, r2 *= r2;
  double r = dist2(a, b);
  double p = (r1 - r2) / r;
  double q = sqrt(abs(2 * (r1 + r2) / r - p * p - 1));

  vector< pdd > ans;
  for(int k = -1; k < 2; k += 2){
    double x = ((x1 + x2) + p * (x2 - x1) + k * q * (y2 - y1)) / 2;
    double y = ((y1 + y2) + p * (y2 - y1) + k * q * (x1 - x2)) / 2;
    ans.PB(MP(x, y));
  }

  return ans;
}

pdd Subtract(pdd a, pdd b){
  double x1 = a.first, y1 = a.second;
  double x2 = b.first, y2 = b.second;
  return MP(x1 - x2, y1 - y2);
}

pdd ChooseValid(pdd a, pdd b, pdd s, vector< pdd > v){
  for(auto t : v){
    if(CrossProductSign(a, b) == CrossProductSign(Subtract(s, p[0]), Subtract(t, p[0]))){
      return t;
    }
  }
}

pdd TargetPoint(pdd s, int i, int k){
  return ChooseValid(p[i], p[k], s, TargetPoints(s, p[0], dist(p[i], p[k]), d[k]));
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  p[0].first = 0, p[0].second = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%lf%lf", &p[i].first, &p[i].second);
    p[0].first += p[i].first;
    p[0].second += p[i].second;
  }

  p[0].first /= n, p[0].second /= n;

  pdd s = p[1];
  for(int i = 1; i <= n; ++i){
    d[i] = dist(p[i], p[0]);
    p[i].first -= p[0].first;
    p[i].second -= p[0].second;
  }

  int i = 1, j = 2;

  while(q--){
    int t;
    scanf("%d", &t);{
      if(t == 1){
        int l, r;
        scanf("%d%d", &l, &r);
        if(l == i && i != j){
          s = TargetPoint(s, i, j);
          swap(i, j);
          p[0] = MP(s.first, s.second - d[i]);
        }
        j = r;
      }
      else{
        int k;
        scanf("%d", &k);
        pdd ans = TargetPoint(s, i, k);
        printf("%.15lf %.15lf\n", ans.first, ans.second);
      }
    }
  }

  return 0;
}
