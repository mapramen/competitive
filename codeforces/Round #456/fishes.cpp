#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tlii tuple< ll, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple

int n, m, r;
set< pii > S;
priority_queue< tlii > Q;

ll GetCount(int x, int y){
  int a = max(0, min(x, n - r + 1) - max(1, x - r + 1) + 1);
  int b = max(0, min(y, m - r + 1) - max(1, y - r + 1) + 1);
  return 1ll * a * b;
}

void CheckAndAdd(int x, int y){
  if(x < 0 || y < 0 || x > n || y > m || S.find(MP(x, y)) != S.end())
    return ;
  S.insert(MP(x, y));
  Q.push(MT(GetCount(x, y), x, y));
}

int main(){
  int k;
  ll ans = 0;

  cin >> n >> m >> r >> k;

  CheckAndAdd((n + 1) / 2, (m + 1) / 2);

  while(k--){
    int x, y;
    ll ansx;
    tie(ansx, x, y) = Q.top();
    Q.pop();

    ans += ansx;

    for(int dx = -1; dx < 2; ++dx)
      for(int dy = -1; dy < 2; ++dy)
        CheckAndAdd(x + dx, y + dy);
  }

  ll t = 1ll * (n - r + 1) * (m - r + 1);

  printf("%.15lf\n", (double)ans / t);

  return 0;
}
