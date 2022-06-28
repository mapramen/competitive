#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2000001
#define MOD 1000000007

char s[N];

int main(){
  scanf("%s", s);

  int n = strlen(s);

  int ans = 0;
  for(int i = n - 1, p = 1, x = 0; i != -1; --i, p = (10ll * p) % MOD){
    x = (x + p) % MOD;
    ans = (ans + 1ll * (i + 1) * (s[i] - '0') * x) % MOD;
  }

  printf("%d\n", ans);
  
  return 0;
}