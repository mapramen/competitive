#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void Solve(){
  string s;
  int mask = 0;

  cin >> s;
  for(auto c : s)
    mask ^= (1 << (c - '0'));

  reverse(s.begin(), s.end());

  for(int i = 0, n = s.size(); i < n; ++i){
    int d = s[i] - '0';
    mask ^= (1 << d);
    for(int j = d - 1; j > -1 + (i == n - 1); --j){
      mask ^= (1 << j);
      s[i] = '0' + j;
      if(__builtin_popcount(mask) <= i){
        for(int x = 0; x < i; ++x){
          if(mask == 0)
            s[x] = '9';
          else{
            int k = 0;
            for( ; (mask & (1 << k)) == 0; ++k);
            s[x] = '0' + k;
            mask ^= (1 << k);
          }
        }
        reverse(s.begin(), s.end());
        cout << s << '\n';
        return ;
      }
      mask ^= (1 << j);
    }
  }

  int n = s.size() - 2;
  while(n--)
    putchar('9');
  putchar('\n');

}

int main(){
  int t;

  cin >> t;
  while(t--)
    Solve();

  return 0;
}
