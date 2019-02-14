#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, k;
  map<int,int> m;

  scanf("%lld%lld", &n, &k);

  for(int i = 59; i > -1; --i){
    ll j = (1ll << i);
    if(j <= n){
      m[i] = 1;
      n -= j;
      --k;
    }
  }

  while(true){
    auto it = m.rbegin();
    if(it->second <= k){
      int x = it->first;
      int y = it->second;
      m[x - 1] += 2 * y;
      k -= y;
      m.erase(x);
    }
    else
      break;
  }

  while(k > 0){
    int x = m.begin()->first;
    m[x - 1] += 2;
    --m[x];
    --k;
    if(m[x] == 0)
      m.erase(x);
  }

  if(k != 0){
    printf("No\n");
  }
  else{
    printf("Yes\n");
    for(auto it = m.rbegin(); it != m.rend(); ++it){
      int x = it->first, y = it->second;
      while(y--){
        printf("%d ", x);
      }
    }
    printf("\n");
  }

  return 0;
}
