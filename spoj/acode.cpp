#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  string s;
  cin >> s;

  if(s.front() == '0'){
    exit(0);
  }

  ll skipCount = 0, count = 1;
  for(int n = s.size(), i = 0; i < n; ++i){
    int x = s[i] - '0';
    int y = i != 0 ? s[i - 1] - '0' : 9;
    y = 10 * y + x;

    ll ans = 0;
    if(x != 0){
      ans += count;
    }

    if(y != x && y <= 26){
      ans += skipCount;
    }

    skipCount = count, count = ans;
  }

  return count;
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}