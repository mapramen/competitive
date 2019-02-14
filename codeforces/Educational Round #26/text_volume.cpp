#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans = 0;

  cin >> n;
  while(n > 0){
    int ansx = 0;
    string s;
    cin >> s;
    for(auto c : s)
      ansx += (c >= 'A' && c <= 'Z');
    ans = max(ans, ansx);
    n -= (s.size() + 1);
  }

  cout << ans << '\n';
  
  return 0;
}
