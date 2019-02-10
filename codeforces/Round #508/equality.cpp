#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 26

int c[B];

int main(){
  int n, k;
  string s;

  cin >> n >> k >> s;

  for(auto x : s){
    ++c[(x - 'A')];
  }

  int ans = n;
  for(int i = 0; i < k; ++i){
    ans = min(ans, c[i]);
  }

  ans *= k;

  cout << ans << '\n';

  return 0;
}
