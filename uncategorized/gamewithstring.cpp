#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 26

int f[B];

int main(){
  int n;
  string s;

  cin >> s;
  n = s.size();
  s += s;

  double ans = 0;
  for(char c = 'a'; c <= 'z'; ++c){
    vector<int> v;
    for(int i = 0; i < n; ++i){
      if(s[i] == c){
        v.PB(i);
      }
    }
    int ansx = 0;
    for(int j = 0; j < n; ++j){
      for(int k = 0; k < B; ++k)
        f[k] = 0;
      for(auto x : v)
        ++f[s[x + j] - 'a'];
      int ansy = 0;
      for(int k = 0; k < B; ++k)
        ansy += (f[k] == 1);
      ansx = max(ansx, ansy);
    }
    ans += ansx;
  }

  ans /= n;

  printf("%.15lf\n", ans);

  return 0;
}
