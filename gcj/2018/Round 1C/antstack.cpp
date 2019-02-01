#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

ll inf = 1E18;

int Solve(){
  int n;

  scanf("%d", &n);

  vector<ll> v(n + 2, inf);
  v[0] = 0;

  while(n--){
    ll w;
    scanf("%lld", &w);

    int i = upper_bound(v.begin(), v.end(), 6 * w) - v.begin();

    for( ; i > 0; --i)
      v[i] = min(v[i], v[i - 1] + w);
  }

  return (int)(lower_bound(v.begin(), v.end(), inf) - v.begin() - 1);
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k)
    printf("Case #%d: %d\n", k, Solve());

  return 0;
}
