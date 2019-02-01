#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int a[N];

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  for(int i = n; i > 0; --i){
    a[i] -= a[i - 1];
  }

  vector<int> ans;
  for(int k = 1; k <= n; ++k){
    bool valid = 1;
    for(int i = k + 1; i <= n && valid; ++i){
      valid = (a[i] == a[i - k]);
    }
    if(valid){
      ans.PB(k);
    }
  }

  cout << ans.size() << '\n';
  for(auto k : ans){
    cout << k << ' ';
  }
  cout << '\n';

  return 0;
}
