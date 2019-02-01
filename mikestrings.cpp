#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int inf = INT_MAX / 2;
vector<string> v;

int main(){
  int n, ans = inf;

  cin >> n;
  for(int i = 1; i <= n; i++){
    string s;
    cin >> s;
    v.PB(s + s);
  }

  for(int x = 0, m = v[0].size() / 2; x < m; x++){
    string s = string(v[0], x, m);
    int ansx = 0;
    for(auto sx : v){
      int i = 0;
      for( ; i < m && string(sx, i, m) != s; i++);
      if(i == m){
        ansx = inf;
        break;
      }
      else
        ansx += i;
    }
    ans = min(ans, ansx);
  }

  if(ans == inf)
    ans = -1;

  cout << ans << '\n';

  return 0;
}
