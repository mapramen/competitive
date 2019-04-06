#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int Damage(string s){
  int ans = 0, x = 1;
  for(int i = 0; i < s.size(); ++i){
    char c = s[i];
    if(c == 'C')
      x *= 2;
    else
      ans += x;
  }
  return ans;
}

bool FixOneStep(string &s){
  for(int i = s.size() - 1; i > -1; --i){
    if(s[i] == 'C' && s[i + 1] == 'S'){
      swap(s[i], s[i + 1]);
      return 1;
    }
  }
  return 0;
}

void Solve(){
  int n, ans = 0;
  string s;

  cin >> n >> s;
  while(Damage(s) > n && FixOneStep(s))
    ++ans;

  if(Damage(s) > n)
    cout << "IMPOSSIBLE\n";
  else
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
