#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 102

int a[N];

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  a[n + 1] = 1001;
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j){
      if(a[j + 1] - a[i - 1] - 1 == j - i + 1){
        ans = max(ans, j - i + 1);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
