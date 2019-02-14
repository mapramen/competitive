#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  string ans;

  cin >> n;

  if(n % 2)
    ans = "contest";
  else
    ans = "home";

  cout << ans << '\n';
  
  return 0;
}
