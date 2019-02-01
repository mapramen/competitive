#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void Solve(){
  int n;
  string s, ans = "Impossible";

  cin >> s;
  n = s.size();

  for(int i = 1; i <= n; ++i){
    int j = i, k = 0;
    for( ; j <= n && s[j - 1] == s[k]; ++j, ++k);

    if(j > n || k == 0){
      continue;
    }

    ans = string(s, 0, j - 1) + string(s, k);
  }

  cout << ans << '\n';
}

int main(){
  int t;

  cin >> t;
  for(int k = 1; k <= t; ++k){
    cout << "Case #" << k << ": ";
    Solve();
  }

  return 0;
}
