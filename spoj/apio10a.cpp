#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef ll ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
  return (conj(a) * b).x();
}

ftype cross(point a, point b) {
  return (conj(a) * b).y();
}

vector<point> hull, vecs;

void add_line(ftype k, ftype b) {
  point nw = {k, b};
  while(!vecs.empty() && dot(vecs.back(), nw - hull.back()) > 0) {
    hull.pop_back();
    vecs.pop_back();
  }
  if(!hull.empty()) {
    point temp(0, 1);
    vecs.push_back(temp * (nw - hull.back()));
  }
  hull.push_back(nw);
}

ll get(ftype x) {
  point query = {x, 1};
  auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point a, point b) {
    return cross(a, b) < 0;
  });
  return dot(query, hull[it - vecs.begin()]);
}

ll Solve(){
  int n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);

  hull.clear(), vecs.clear();

  ll s = 0, ans = 0;
  while(n--){
    add_line(-2 * a * s, ans + a * s * s);
    
    int x;
    scanf("%d", &x);
    s += x;

    ans = get(s) + a * s * s + c;
  }

  ans += b * s;

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}