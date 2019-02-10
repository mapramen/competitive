#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  string s;

  cin >> n >> s;

  int ans = n;
  for(int i = 0; 2 * i < n; ++i){
    if(string(s, 0, i + 1) == string(s, i + 1, i + 1))
      ans = min(ans, n - i);
  }

  cout << ans << '\n';

  return 0;
}
