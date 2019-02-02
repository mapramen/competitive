#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void Reverse(vector<int>& v){
  reverse(v.begin(), v.end());
}

void ScanlineSolve(int n, vector< pii > a, vector<int>& yMin, vector<int>& yMax, bool doReverse){
  for(auto p : a){
    int x, y;
    tie(x, y) = p;
    x += (1 - doReverse);
    yMin[x] = min(yMin[x], y + 1);
    yMax[x] = max(yMax[x], y);
  }

  if(doReverse){
    Reverse(yMin);
    Reverse(yMax);
  }

  for(int i = 1; i <= n; ++i){
    yMin[i] = min(yMin[i], yMin[i - 1]);
    yMax[i] = max(yMax[i], yMax[i - 1]);
  }

  if(doReverse){
    Reverse(yMin);
    Reverse(yMax);
  }
}

ll GetCount(vector< pii > a){
  int min_x = INT_MAX, max_x = INT_MIN;

  for(int i = 0; i < a.size(); ++i){
    int x = (a[i].first + a[i].second - 1) / 2, y = (a[i].first - a[i].second - 1) / 2;
    min_x = min(min_x, x);
    max_x = max(max_x, x);
    a[i] = MP(x, y);
  }

  for(int i = 0; i < a.size(); ++i)
    a[i].first -= min_x;

  int n = max_x - min_x + 1;
  vector<int> yLeftMin(n + 1, INT_MAX), yLeftMax(n + 1, INT_MIN);
  vector<int> yRightMin(n + 1, INT_MAX), yRightMax(n + 1, INT_MIN);

  ScanlineSolve(n, a, yLeftMin, yLeftMax, 0);
  ScanlineSolve(n, a, yRightMin, yRightMax, 1);

  ll ans = 0;
  for(int i = 0; i < n + 1; ++i){
    if(yLeftMin[i] == INT_MAX || yRightMin[i] == INT_MAX || yLeftMax[i] == INT_MIN || yRightMax[i] == INT_MIN){
      continue;
    }

    int yMin = max(yLeftMin[i], yRightMin[i]);
    int yMax = min(yLeftMax[i], yRightMax[i]);

    ans += max(0, yMax - yMin + 1);
  }

  return ans;
}

int main(){
  int n;
  vector< pii > odds, evens;

  scanf("%d", &n);

  while(n--){
    int x, y;
    scanf("%d%d", &x, &y);
    if((400000 + x + y) % 2 == 1)
      odds.PB(MP(x, y));
    else
      evens.PB(MP(x, y + 1));
  }

  ll ans = GetCount(odds) + GetCount(evens);

  printf("%lld\n", ans);

  return 0;
}
