#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001

pii points[N];

double Distance(pii a, pii b){
  int dx = b.first - a.first, dy = b.second - a.second;
  return sqrt(1ll * dx * dx + 1ll * dy *dy);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &points[i].first, &points[i].second);
  }

  vector<int> indexes;
  for(int i = 1; i <= n; ++i){
    indexes.push_back(i);
  }
  sort(indexes.begin(), indexes.end(), [](int i, int j) { return points[i] < points[j]; });

  map<int,int> M;

  double ans = 1E9;
  int ans_i = 0, ans_j = 0;

  for(int j: indexes){
    int x2 = points[j].first, y2 = points[j].second;
    
    for(int y = y2 - ans - 1; y - y2 <= ans && !M.empty() && y <= M.rbegin()->first; ++y){
      auto it = M.lower_bound(y);
      int i = it->second;

      int x1 = points[i].first;
      y = points[i].second;

      if(x2 - x1 > ans){
        M.erase(it);
        continue;
      }

      double d = Distance(points[i], points[j]);
      if(d < ans){
        ans = d, ans_i = i, ans_j = j;
      }
    }

    M[y2] = j;
  }

  if(ans_i > ans_j){
    swap(ans_i, ans_j);
  }

  printf("%d %d %.6lf\n", ans_i - 1, ans_j - 1, ans);
  
  return 0;
}