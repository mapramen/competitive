#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char s[N];

bool IsPrime(int n){
  if(n == 1){
    return false;
  }

  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return false;
    }
  }

  return true;
}

ll Solve(){
  int n;
  scanf("%d%s", &n, s);

  ll ans = 0;
  for(int i = n - 1, j = n; i != -1; --i){
    if(IsPrime(s[i] - 'A' + 1)){
      j = i;
    }
    ans += (n - j);
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