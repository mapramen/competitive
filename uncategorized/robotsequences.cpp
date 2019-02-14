#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans;
  string s;
  map< pii, int > m;

  cin >> n >> s;

  m[MP(0,0)] = 1;

  for(int i = 0, x = 0, y = 0; i < s.size(); i++){
    char c = s[i];

    if(c == 'U')
      y++;
    else if(c == 'D')
      y--;
    else if(c == 'R')
      x++;
    else
      x--;

    m[MP(x, y)]++;
  }

  ans = 0;
  for(auto p : m){
    int x = p.second;
    ans += (x * (x - 1)) / 2;
  }

  cout << ans << '\n';
  
  return 0;
}
