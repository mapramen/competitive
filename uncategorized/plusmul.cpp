#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define MOD 1000000007

ll C[N];

void PreProcess(){
  C[0] = C[1] = 1;
  for(int i = 2; i < N; i++)
    C[i] = (2 * C[i - 1]) % MOD;
}

int main(){
  int t;

  PreProcess();

  scanf("%d", &t);
  while(t--){
    int n;
    ll T = 0, S = 0, ans = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
      int a;
      scanf("%d", &a);
      S = ((S + C[i - 1]) * a) % MOD;
      ans = (T + S) % MOD;
      T = (T + ans) % MOD;
    }

    printf("%lld\n", ans);
  }
  
  return 0;
}
