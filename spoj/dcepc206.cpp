#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

ll T[N];

void Reset(){
  for(int i = 0; i < N; ++i){
    T[i] = 0;
  }
}

void Update(int i, int x){
  for( ; i != 0 && i < N; i += (i & -i)){
    T[i] += x;
  }
}

ll Query(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  Reset();

  ll ans = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    Update(x, x);
    ans += Query(x - 1);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}