#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  ll n;
  scanf("%lld", &n);
  printf("%s\n", (n & (n - 1)) == 0 ? "TAK" : "NIE");
  return 0;
}