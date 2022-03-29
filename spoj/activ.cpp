#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define MOD 100000000

pii a[N];
int T[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    T[i] = 0;
  }
}

void Update(int n, int i, int x){
  for( ; i <= n; i += (i & -i)){
    T[i] = (T[i] + x) % MOD;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans = (ans + T[i]) % MOD;
  }
  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == -1){
    exit(0);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].second, &a[i].first);
  }
  sort(a + 1, a + n + 1);

  Reset(n);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int k = lower_bound(a + 1, a + n + 1, make_pair(a[i].second + 1, 0)) - a - 1;
    int ansx = (1 + Query(k)) % MOD;
    
    Update(n, i, ansx);
    ans = (ans + ansx) % MOD;
  }

  return ans;
}

int main(){
  while(true){
    printf("%08d\n", Solve());
  }
  return 0;
}