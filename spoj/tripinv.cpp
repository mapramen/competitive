#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 3
#define N 100001

ll T[B][N];

void Update(ll T[], int i, ll x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int main(){
  Update(T[0], 1, 1);

  int n;
  scanf("%d", &n);

  ll ans = 0;
  while(n--){
    int i;
    scanf("%d", &i);
    i = N - i;

    ans += Query(T[B - 1], i - 1);

    for(int k = 1; k < B; ++k){
      Update(T[k], i, Query(T[k - 1], i - 1));
    }
  }

  printf("%lld\n", ans);

  return 0;
}