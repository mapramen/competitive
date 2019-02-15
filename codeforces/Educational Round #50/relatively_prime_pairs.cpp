#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll l, r;

  scanf("%lld%lld", &l, &r);

  printf("YES\n");
  for(ll i = l; i <= r; i += 2){
    printf("%lld %lld\n", i, i + 1);
  }

  return 0;
}
