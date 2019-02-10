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
    ++ans;
    if(i + 1 < n && s[i] != s[i + 1])
      ++i;
  }

  cout << ans << '\n';

  return 0;
}
