#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  ll n;
  scanf("%lld", &n);

  int d = n % 10;

  printf("%d\n", 1 + (d == 0));
  if(d != 0){
    printf("%d\n", d);
  }

  return 0;
}