#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define L 10

ll p[L], s[L];

void Initialise(){
  s[0] = 0;

  ll x = 1;
  for(int i = 1; i < L; ++i, x *= 10){
    s[i] = 45 * i * x;
  }

  x = 1;
  for(int i = 0; i < L; ++i, x *= 10){
    p[i] = x;
  }
}

vector<int> GetDigits(int m){
  vector<int> v;
  for( ; m > 0; m /= 10){
    v.push_back(m % 10);
  }
  return v;
}

ll GetSum(int m){
  if(m <= 0){
    return 0ll;
  }

  vector<int> v = GetDigits(m);

  ll ans = 0;
  for(int n = v.size() - 1; n != -1; --n){
    int d = v[n];
    for(int dx = 0; dx < d; ++dx){
      ans += s[n] + dx * p[n];
    }
    ans += d * (m % p[n] + 1);
  }

  return ans;
}

ll Solve(){
  int a, b;
  scanf("%d%d", &a, &b);

  if(a == -1){
    exit(0);
  }

  return GetSum(b) - GetSum(a - 1);
}

int main(){
  Initialise();
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}