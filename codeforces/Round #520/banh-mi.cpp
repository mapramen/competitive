#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define MOD 1000000007

char s[N];
int zeros[N], p2[N];

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  scanf("%s", s);

  for(int i = 1; i <= n; ++i){
    zeros[i] = zeros[i - 1] + (s[i - 1] == '0');
  }

  p2[0] = 1;
  for(int i = 1; i <= n; ++i){
    p2[i] = (2 * p2[i - 1]) % MOD;
  }

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    int a = (zeros[r] - zeros[l - 1]);
    int ans = (p2[r - l + 1] + MOD - p2[a]) % MOD;
    printf("%d\n", ans);
  }

  return 0;
}
