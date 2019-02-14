#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans = 0;
  string s;

  cin >> n >> s;

  for(int i = 0; i < n; ++i){
    if('A' <= s[i] && s[i] <= 'Z')
      continue;

    set<char> S;
    for(int j = i; j < n; ++j){
      if('a' <= s[j] && s[j] <= 'z')
        S.insert(s[j]);
      else
        break;
    }

    ans = max(ans, (int)S.size());
  }

  cout << ans << '\n';

  return 0;
}
