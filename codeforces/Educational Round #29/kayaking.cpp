#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m, ans = INT_MAX;
  vector<int> v;

  cin >> n;
  m = 2 * n;
  for(int i = 0; i < m; ++i){
    int j;
    cin >> j;
    v.PB(j);
  }

  for(int i = 0; i < m; ++i){
    for(int j = i + 1; j < m; ++j){
      vector<int> a;
      for(int k = 0; k < m; ++k){
        if(k == i || k == j)
          continue;
        a.PB(v[k]);
      }
      sort(a.begin(), a.end());

      int ansx = 0;
      for(int k = 0; k < a.size(); k += 2)
        ansx += (a[k + 1] - a[k]);
      ans = min(ans, ansx);
    }
  }

  cout << ans << '\n';

  return 0;
}
