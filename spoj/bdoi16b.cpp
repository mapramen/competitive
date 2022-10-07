#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int PrimePowerInFactorial(int n, int p){
  int ans = 0;
  for( ; n >= p; n /= p){
    ans += n / p;
  }
  return ans;
}

int CalculatePower(int p, int a, int& b){
  int k = 0;
  for( ; b % p == 0; b /= p, ++k);
  return PrimePowerInFactorial(a, p) / k;
}

int Solve(){
  int a, b;
  scanf("%d%d", &a, &b);

  int ans = INT_MAX;
  for(int p = 2; p * p <= b; ++p){
    if(b % p != 0){
      continue;
    }
    ans = min(ans, CalculatePower(p, a, b));
  }

  if(b != 1){
    ans = min(ans, CalculatePower(b, a, b));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}