#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int a[N], b[N];

int main(){
  int n, r;

  cin >> n >> r;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  int ans = 0;
  for(int i = 1, j = 1; i <= n; ++i){
    if(b[i] == 1){
      continue;
    }

    int k = -1;
    for( ; abs(j - i) < r && j <= n; ++j){
      if(a[j] == 1){
        k = j;
      }
    }

    if(k < 0){
      ans = -1;
      break;
    }

    ++ans;
    for(int j = max(1, k - r + 1); j <= min(n, k + r - 1); ++j){
      b[j] = 1;
    }
  }

  cout << ans << '\n';

  return 0;
}
