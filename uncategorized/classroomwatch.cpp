#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

bool Check(int n, int s){
  while(n){
    s -= n % 10;
    n /= 10;
  }
  return (s == 0);
}

int main(){
  int n;
  vector<int> ans;

  cin >> n;

  for(int i = max(1, n - 90); i <= n; ++i){
    if(Check(i, n - i))
      ans.PB(i);
  }

  cout << ans.size() << '\n';
  for(auto x : ans)
    cout << x << '\n';

  return 0;
}
