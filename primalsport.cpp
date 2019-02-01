#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int lpd[N];

int main(){
  int n;

  cin >> n;

  for(int i = 2; i <= n; ++i){
    if(lpd[i])
      continue;
    for(int j = i; j <= n; j += i)
      lpd[j] = i;
  }

  int ans = n;
  for(int i = max(2, n - lpd[n] + 1); i <= n; ++i){
    if(lpd[i] == i)
      ans = min(ans, i);
    else
      ans = min(ans, max(2, i - lpd[i] + 1));
  }

  cout << ans << '\n';

  return 0;
}
