#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

double Query(vector<pii> v){
  printf("? %lu\n", v.size());
  for(pii p: v){
    printf("%d %d\n", p.first, p.second);
  }
  fflush(stdout);

  double ans;
  scanf("%lf", &ans);
  return ans;
}

vector<pii> GetYPolygon(int n, int m){
  vector<pii> v{{0, m + 1}};
  for(int x = 0; x < n; ++x){
    v.push_back({x, 0});
    v.push_back({x + 1, m});
  }
  v.push_back({n, m + 1});
  return v;
}

vector<pii> GetXPolygon(int n, int m){
  vector<pii> v = GetYPolygon(m, n);
  for(pii& p: v){
    swap(p.first, p.second);
  }
  return v;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  double x = n * Query(GetXPolygon(n, m)) - 0.5;
  double y = m * Query(GetYPolygon(n, m)) - 0.5;

  printf("! %.15lf %.15lf\n", x, y);
  fflush(stdout);

  return 0;
}