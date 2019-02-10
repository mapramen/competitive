#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  map< int, int > M;

  cin >> n;
  while(n--){
    int i;
    cin >> i;
    ++M[i];
  }

  int ans = 0;
  for(auto it : M)
    ans = max(ans, it.second);

  cout << ans << '\n';

  return 0;
}
