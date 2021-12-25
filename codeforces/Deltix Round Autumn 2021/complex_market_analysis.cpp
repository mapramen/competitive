#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

bool isPrime[N];
int a[N];

void Initialise(){
  for(int i = 2; i < N; ++i){
    isPrime[i] = true;
  }

  for(int i = 2; i * i < N; ++i){
    if(!isPrime[i]){
      continue;
    }

    for(int j = 2 * i; j < N; j += i){
      isPrime[j] = false;
    }
  }
}

ll Solve(){
  int n, e;
  scanf("%d%d", &n, &e);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    if(!isPrime[a[i]]){
      continue;
    }

    int x = 1;
    for(int j = i - e; j > 0 && a[j] == 1; ++x, j -= e);

    int y = 1;
    for(int j = i + e; j <= n && a[j] == 1; ++y, j += e);

    ans += (1ll * x * y - 1);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  Initialise();

  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}