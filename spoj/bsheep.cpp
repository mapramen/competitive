#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Cross(pii p, pii q){
  return 1ll * p.first * q.second - 1ll * p.second * q.first;
}

ll Area2(pii a, pii b, pii c){
  return Cross(a, b) + Cross(b, c) + Cross(c, a);
}

double Dis(pii a, pii b){
  int dx = a.first - b.first, dy = a.second - b.second;
  return sqrt(1ll * dx * dx + 1ll * dy * dy);
}

vector<pii> ConvexHull(vector<pii> pts) {
  sort(pts.begin(), pts.end(), [](pii& a, pii& b) { return make_pair(a.second, a.first) < make_pair(b.second, b.first); });
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  
  vector<pii> up, dn;
  
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && Area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && Area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }

  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

  return pts;
}

void Solve(){
  int n;
  scanf("%d", &n);

  map<pii,int> index_map;
  vector<pii> pts;

  for(int i = 1; i <= n; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    pts.push_back({x, y});
  }

  for(int i = n - 1; i != -1; --i){
    index_map[pts[i]] = i + 1;
  }

  vector<pii> hull = ConvexHull(pts);

  double ans = 0;
  for(int i = 0, m = hull.size(); i < hull.size(); ++i){
    ans += Dis(hull[i], hull[(i + 1) % m]);
  }

  printf("%.2lf\n", ans);
  for(pii& p: hull){
    printf("%d ", index_map[p]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
    if(t != 0){
      printf("\n");
    }
  }
  return 0;
}