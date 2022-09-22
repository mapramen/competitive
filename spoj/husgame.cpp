#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(ll n){
  if(n == 1){
    return false;
  }

  if(n % 2 == 0){
    return true;
  }

  return !Solve((n + 1) / 2);
}

bool Solve(){
  ll n;
  scanf("%lld", &n);
  return n == 1 || Solve(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "HuseyNO" : "ZiYES");
  }
  return 0;
}