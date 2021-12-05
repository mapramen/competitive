#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pdd pair<double,double>
#define pid tuple<int,double>
#define pll pair<ll,ll>
#define N 3001

double PI = 4 * atan(1), EPS = 1e-9;
pii points[N];
bool isValid[N][N];

vector<pdd> GetAngleIntervals(double al, double ar){
  while(al < 0){
    al += 2 * PI, ar += 2 * PI;
  }
  
  if(ar <= 2 * PI){
    return {{al, ar}};
  }

  return {{al, 2 * PI}, {0, ar - 2 * PI}};
}

void UpdateOverlappingAngleIntervals(vector<pdd>& v, double angle, double dangle){
  vector<pdd> u;

  for(auto [bl, br]: GetAngleIntervals(angle - dangle, angle + dangle)){
    for(auto [al, ar]: v){
      double l = max(al, bl), r = min(ar, br);
      if(l <= r){
        u.push_back({l, r});
      }      
    }
  }

  sort(u.begin(), u.end());
  reverse(u.begin(), u.end());
  v.clear();

  while(!u.empty()){
    auto [l, r] = u.back();
    
    while(!u.empty() && u.back().first <= r + EPS){
      r = max(r, u.back().second);
      u.pop_back();
    }

    v.push_back({l, r});
  }
}

bool IsBetweenAngleIntervals(vector<pdd>& a, double angle){
  while(angle < 0){
    angle += 2 * PI;
  }

  for(auto [al, ar]: a){
    if(al - EPS <= angle && angle <= ar + EPS){
      return true;
    }
  }

  return false;
}

void Populate(int n, int R, int i){
  vector<pid> v;

  vector<pdd> angleIntervals = {{0, 2 * PI}};
  for(int j = 1; j <= n && !angleIntervals.empty(); ++j){
    if(j == i){
      continue;
    }

    int dx = points[j].first - points[i].first;
    int dy = points[j].second - points[i].second;
    ll d = 1ll * dx * dx + 1ll * dy * dy - 1ll * R * R;

    double angle = atan2(dy, dx);
    if(d > 0){
      UpdateOverlappingAngleIntervals(angleIntervals, angle, atan(R / sqrt(d)));
    }

    v.push_back({j, angle});
  }

  for(auto [j, angle]: v){
    isValid[i][j] = IsBetweenAngleIntervals(angleIntervals, angle);
  }

  v.clear();
}

int main(){
  int n, R;
  scanf("%d%d", &n, &R);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &points[i].first, &points[i].second);
  }

  for(int i = 1; i <= n; ++i){
    Populate(n, R, i);
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      ans += isValid[i][j] && isValid[j][i];
    }
  }

  printf("%d\n", ans);

  return 0;
}