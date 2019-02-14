#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int inf = 1E9;

pii fMin(pii a, pii b){
  int p1, q1, p2, q2;
  tie(p1, q1) = a;
  tie(p2, q2) = b;
  if(1ll * p1 * q2 - 1ll * p2 * q1 <= 0)
    return a;
  else
    return b;
}

pii fMax(pii a, pii b){
  int p1, q1, p2, q2;
  tie(p1, q1) = a;
  tie(p2, q2) = b;
  if(1ll * p1 * q2 - 1ll * p2 * q1 >= 0)
    return a;
  else
    return b;
}

pii GetMinTime(int r, int v, int x1, int x2){
  pii ans;

  if(v == 0)
    if(x1 < r && r < x2)
      ans = MP(-inf, 1);
    else
      ans = MP(inf, 1);
  else{
    x1 -= r, x2 -= r;
    if(v < 0)
      v = -v, x1 = -x1, x2 = -x2;

    pii a = MP(x1, v);
    pii b = MP(x2, v);
    ans = fMin(a, b);
  }

  return ans;
}

pii GetMaxTime(int r, int v, int x1, int x2){
  pii ans;

  if(v == 0)
    if(x1 < r && r < x2)
      ans = MP(inf, 1);
    else
      ans = MP(-inf, 1);
  else{
    x1 -= r, x2 -= r;
    if(v < 0)
      v = -v, x1 = -x1, x2 = -x2;

    pii a = MP(x1, v);
    pii b = MP(x2, v);
    ans = fMax(a, b);
  }

  return ans;
}

int main(){
  int n, x1, x2, y1, y2;
  pii T1 = MP(0, 1), T2 = MP(inf, 1);

  scanf("%d", &n);

  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

  if(x1 > x2)
    swap(x1, x2);

  if(y1 > y2)
    swap(y1, y2);

  while(n--){
    int rx, ry, vx, vy;
    scanf("%d%d%d%d", &rx, &ry, &vx, &vy);
    pii t1 = fMax(GetMinTime(rx, vx, x1, x2), GetMinTime(ry, vy, y1, y2));
    pii t2 = fMin(GetMaxTime(rx, vx, x1, x2), GetMaxTime(ry, vy, y1, y2));
    T1 = fMax(T1, t1);
    T2 = fMin(T2, t2);
  }

  if(1ll * T1.first * T2.second - 1ll * T2.first * T1.second >= 0)
    printf("-1\n");
  else
    printf("%.15lf\n", 1.0 * T1.first / T1.second);

  return 0;
}
