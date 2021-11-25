#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200002
#define MOD 998244353 

int T[N];

void Update(int i, int x){
  for(++i; i < N; i += (i & -i)){
    T[i] = (T[i] + x) % MOD;
  }
}

int Query(int i){
  int ans = 0;
  for(++i; i > 0; i -= (i & -i)){
    ans = (ans + T[i]) % MOD;
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  Update(0, 1);
  int ans = 1;

  while(n--){
    int x;
    scanf("%d", &x);
    int ansx = Query(x - 1);
    ans = (ans + ansx) % MOD;
    Update(x, ansx);
  }

  printf("%d\n", ans);

  return 0;
}