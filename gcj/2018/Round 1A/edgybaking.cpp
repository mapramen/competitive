#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define PB push_back
#define MP make_pair

void MergeOverlaps(vector< pdd >& v){
  vector< pdd > ans;

  sort(v.begin(), v.end());

  for(int i = 0; i < v.size(); ){
    double l = v[i].first, r = v[i].second;
    int j;
    for(j = i + 1; j < v.size(); ++j){
      if(v[j].first <= r)
        r = max(r, v[j].second);
      else
        break;
    }
    ans.PB(MP(l, r));
    i = j;
  }

  v.clear();
  for(pdd p : ans)
    v.PB(p);

  ans.clear();
}

double Solve(){
  int n, p;
  double ans = 0;

  scanf("%d%d", &n, &p);

  vector< pdd > v;
  v.PB(MP(0.0, 0.0));

  for(int i = 1; i <= n; ++i){
    int w, h;
    scanf("%d%d", &w, &h);
    if(w > h)
      swap(w, h);
    ans += 2 * (w + h);
    p -= 2 * (w + h);

    double l = 2 * w, r = 2 * sqrt(w * w + h * h);
    for(int j = v.size() - 1; j > -1; --j){
      v.PB(MP(v[j].first + l, v[j].second + r));
    }

    MergeOverlaps(v);
  }

  double ansx = 0;
  for(pdd x : v){
    double l = x.first, r = x.second;
    if(l <= p){
      ansx = max(ansx, min(r, 1.0 * p));
    }
  }

  ans += ansx;
  return ans;
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %.15lf\n", k, Solve());
  }

  return 0;
}
