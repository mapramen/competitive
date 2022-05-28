#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int T[N];

void Reset(){
  for(int i = 1; i < N; ++i){
    T[i] = 0;
  }
}

void Update(int i){
  for( ; i < N; i += (i & -i)){
    ++T[i];
  }
}

int Query(int i){
  int ans = 0;
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
  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    ans += (i - Query(x));
    Update(x);
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