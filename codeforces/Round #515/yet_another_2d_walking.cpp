#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector<int> d(1);
set< pii > s[N];
pii levelEnds[N][2];
ll dp[N][2];
const ll inf = 1E18;

void TakeInputs(){
  int n;
  vector< pii > v(1);

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    v.PB(MP(x, y));
    d.PB(max(x, y));
  }

  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());

  for(int i = 0; i <= n; ++i){
    int x, y, k;
    tie(x, y) = v[i];
    k = max(x, y);
    k = lower_bound(d.begin(), d.end(), k) - d.begin();
    s[k].insert(v[i]);
  }
}

int Cost(pii &a, pii &b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
  TakeInputs();

  int n = d.size() - 1;
  ll ans = 0;

  for(int i = 1; i <= n; ++i){
    int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN;
    for(auto p : s[i]){
      int x, y;
      tie(x, y) = p;
      x1 = min(x1, x), x2 = max(x2, x);
      y1 = min(y1, y), y2 = max(y2, y);
    }

    levelEnds[i][0] = (x1 == d[i]) ? MP(d[i], y2) : MP(x1, d[i]);
    levelEnds[i][1] = (y1 == d[i]) ? MP(x2, d[i]) : MP(d[i], y1);

    dp[i][0] = min(Cost(levelEnds[i][0], levelEnds[i - 1][0]) + dp[i - 1][1], Cost(levelEnds[i][0], levelEnds[i - 1][1]) + dp[i - 1][0]);
    dp[i][1] = min(Cost(levelEnds[i][1], levelEnds[i - 1][0]) + dp[i - 1][1], Cost(levelEnds[i][1], levelEnds[i - 1][1]) + dp[i - 1][0]);

    ans += Cost(levelEnds[i][0], levelEnds[i][1]);
  }

  ans += min(dp[n][0], dp[n][1]);

  printf("%lld\n", ans);

  return 0;
}
