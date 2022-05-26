#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500001

char s[N];
int f[N];

int ComputeFailure(int k, char c){
  while(k != 0 && s[k] != c){
    k = f[k];
  }
  return k + (s[k] == c);
}

ll Solve(){
  int m;
  scanf("%s%d", s, &m);

  int n = strlen(s);

  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
  }

  return n + 1ll * (m - 1) * (n - f[n]);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}