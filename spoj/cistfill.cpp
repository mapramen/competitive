#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define t4i tuple<int,int,int,int>

bool Check(double t, int m, vector<t4i>& a){
  double s = 0;
  for(int i = a.size() - 1; i != -1; --i){
    int b = get<0>(a[i]), h = get<1>(a[i]), w = get<2>(a[i]), d = get<3>(a[i]);
    if(t < b){
      continue;
    }
    s += (min(1.0 * b + h, t) - b) * w * d;
  }
  return s >= m;
}

double BinarySearch(int m, vector<t4i>& a){
  double x = 0, y = 2E9;

  for(int iter = 0; iter <= 50; ++iter){
    double mid = x + (y - x) / 2;
    if(Check(mid, m, a)){
      y = mid;
    }
    else{
      x = mid;
    }
  }

  return x + (y - x) / 2;
}

double Solve(){
  int n;
  scanf("%d", &n);

  vector<t4i> a;

  int s = 0;
  while(n--){
    int b, h, w, d;
    scanf("%d%d%d%d", &b, &h, &w, &d);
    a.push_back({b, h, w, d});
    s += h * w * d;
  }

  int m;
  scanf("%d", &m);

  return s < m ? -1 : BinarySearch(m, a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    double ans = Solve();
    if(ans < 0){
      printf("OVERFLOW\n");
    }
    else{
      printf("%.2lf\n", ans);
    }
  }
  return 0;
}