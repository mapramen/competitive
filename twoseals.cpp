#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

pii a[N];

int main(){
  int k, n, m, ans = 0;

  cin >> k >> n >> m;
  for(int i = 1; i <= k; ++i)
    cin >> a[i].first >> a[i].second;

  for(int i = 1; i <= k; ++i){
    for(int j = i + 1; j <= k; ++j){
      for(int fi = 0; fi < 2; ++fi){
        for(int fj = 0; fj < 2; ++fj){
          int x1, y1, x2, y2;
          tie(x1, y1) = a[i];
          tie(x2, y2) = a[j];

          if(fi)
            swap(x1, y1);

          if(fj)
            swap(x2, y2);

          if(max(x1, x2) > n || max(y1, y2) > m)
            continue;

          if(x1 + x2 <= n || y1 + y2 <= m)
            ans = max(ans, x1 * y1 + x2 * y2);
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
