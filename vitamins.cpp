#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 3
#define N (1 << B)

int c[N], inf = 1E9;

int main(){
  int n;

  for(int mask = 0; mask < N; ++mask){
    c[mask] = inf;
  }

  cin >> n;
  while(n--){
    int a, mask = 0;
    string s;

    cin >> a >> s;

    for(auto x : s){
      mask |= (1 << (x - 'A'));
    }

    c[mask] = min(c[mask], a);
  }

  for(int k = 0; k < B; ++k){
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        int x = (i | j);
        c[x] = min(c[x], c[i] + c[j]);
      }
    }
  }

  int ans = (c[N - 1] == inf) ? -1 : c[N - 1];

  cout << ans << '\n';

  return 0;
}
